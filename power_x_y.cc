#include "test_framework/generic_test.h"
double helper(double x, int y){
    if(y == 1) return x;
    double c = x * x;
    double ans = helper(c, y / 2);
    if(y % 2 == 1) ans = ans * x;
    return ans;
}
double Power(double x, int y) {
    if(y == 0) return 1;
    if(y < 0) {
        x = 1 / x;
        y = -y;
    }
    return helper(x, y);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
