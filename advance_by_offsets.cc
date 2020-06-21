#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
bool CanReachEnd(const vector<int>& max_advance_steps) {
    int furthest_reached = 0;
    for(int i = 0;i<=furthest_reached && i < max_advance_steps.size();++i){
        furthest_reached = std::max(furthest_reached, max_advance_steps[i] + i);
    }
    return furthest_reached >= max_advance_steps.size() - 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
