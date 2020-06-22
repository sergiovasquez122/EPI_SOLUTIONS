#include "test_framework/generic_test.h"

int SquareRoot(int k) {
    int low = 0, hi = k;
    while(low <= hi){
      long mid = low + (hi - low) / 2;
      long mid_squared = mid * mid;
      if(mid_squared <= k){
          low = mid + 1;
      } else {
          hi = mid - 1;
      }
    }
    return low - 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k"};
  return GenericTestMain(args, "int_square_root.cc", "int_square_root.tsv",
                         &SquareRoot, DefaultComparator{}, param_names);
}
