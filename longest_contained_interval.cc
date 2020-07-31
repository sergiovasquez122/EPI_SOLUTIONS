#include <vector>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::vector;
using std::unordered_set;

int LongestContainedRange(const vector<int>& A) {
  unordered_set<int> elements(A.cbegin(), A.cend());
  int result = 0;
  while(!elements.empty()){
      int a = *elements.begin();
      elements.erase(a);
      int lower_bound = a - 1;
      int lower_bound_count = 0;
      while(elements.count(lower_bound)){
          elements.erase(lower_bound);
          lower_bound--;
          lower_bound_count++;
      }
      int upper_bound = a + 1;
      int upper_bound_count = 0;
      while(elements.count(upper_bound)){
          elements.erase(upper_bound);
          upper_bound++;
          upper_bound_count++;
      }
      result = std::max(result, upper_bound_count + lower_bound_count + 1);
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "longest_contained_interval.cc", "longest_contained_interval.tsv",
      &LongestContainedRange, DefaultComparator{}, param_names);
}
