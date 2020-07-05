#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int GetMaxTrappedWater(const vector<int>& heights) {
  int left_idx = 0;
  int right_idx = heights.size() - 1;
  int result = std::numeric_limits<int>::min();
  while(left_idx < right_idx){
    int area = std::min(heights[left_idx], heights[right_idx]) * (right_idx - left_idx);
    result = std::max(result, area);
    if(heights[left_idx] < heights[right_idx]){
      left_idx++;
    } else {
      right_idx--;
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  return GenericTestMain(args, "max_trapped_water.cc", "max_trapped_water.tsv",
                         &GetMaxTrappedWater, DefaultComparator{}, param_names);
}
