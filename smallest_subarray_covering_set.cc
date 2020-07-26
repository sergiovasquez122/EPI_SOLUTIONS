#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::unordered_set;
using std::vector;
using std::unordered_map;

struct Subarray {
  int start, end;
};

Subarray FindSmallestSubarrayCoveringSet(
    const vector<string> &paragraph, const unordered_set<string> &keywords) {
  Subarray result {-1, -1};
  unordered_map<string, int> freq_count;
  for(const auto& k : keywords){
    ++freq_count[k];
  }
  int window_start = 0;
  int matches = 0;
  int minimum_length = std::numeric_limits<int>::max();
  for(int window_end = 0;window_end < paragraph.size();++window_end){
    if(freq_count.count(paragraph[window_end])){
      --freq_count[paragraph[window_end]];
      if(freq_count[paragraph[window_end]] == 0){
        matches++;
      }
    }
    while(matches == keywords.size()){
      if(window_end - window_start + 1 < minimum_length){
        result = {window_start, window_end};
        minimum_length = window_end - window_start + 1;
      }
      if(freq_count.count(paragraph[window_start])){
        if(freq_count[paragraph[window_start]] == 0){
            matches--;
        }
        freq_count[paragraph[window_start]]++;
      }
      window_start++;
    }
  }
  return result;
}

int FindSmallestSubarrayCoveringSetWrapper(
    TimedExecutor &executor, const vector<string> &paragraph,
    const unordered_set<string> &keywords) {
  unordered_set<string> copy = keywords;

  auto result = executor.Run(
      [&] { return FindSmallestSubarrayCoveringSet(paragraph, keywords); });

  if (result.start < 0 || result.start >= paragraph.size() || result.end < 0 ||
      result.end >= paragraph.size() || result.start > result.end) {
    throw TestFailure("Index out of range");
  }

  for (int i = result.start; i <= result.end; i++) {
    copy.erase(paragraph[i]);
  }

  if (!copy.empty()) {
    throw TestFailure("Not all keywords are in the range");
  }

  return result.end - result.start + 1;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "paragraph", "keywords"};
  return GenericTestMain(args, "smallest_subarray_covering_set.cc",
                         "smallest_subarray_covering_set.tsv",
                         &FindSmallestSubarrayCoveringSetWrapper,
                         DefaultComparator{}, param_names);
}
