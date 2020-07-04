#include <iterator>
#include <vector>
#include <stack>
#include "test_framework/generic_test.h"
using std::vector;
using std::stack;

struct building{
    int height, idx;
};

vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end) {
    vector<int> result;
    stack<building> candidates;
    int idx = 0;
    while(sequence_begin != sequence_end){
        if(candidates.empty()){
            candidates.push({*sequence_begin++, idx++});
        } else{
            while(!candidates.empty() && candidates.top().height <= *sequence_begin){
                candidates.pop();
            }
            candidates.push({*sequence_begin++, idx++});
        }
    }
    while(!candidates.empty()){
        result.push_back(candidates.top().idx);
        candidates.pop();
    }
    return result;
}

vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int>& sequence) {
  return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "sunset_view.cc", "sunset_view.tsv",
                         &ExamineBuildingsWithSunsetWrapper,
                         DefaultComparator{}, param_names);
}
