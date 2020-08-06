#include "test_framework/generic_test.h"
int Fibonacci(int n) {
    if(n == 0){
        return 0;
    }
    int f0 = 0;
    int f1 = 1;
    for(int i = 2; i <= n;i++){
      int fn = f0 + f1;
      f0 = f1;
      f1 = fn;
    }
    return f1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "fibonacci.cc", "fibonacci.tsv", &Fibonacci,
                         DefaultComparator{}, param_names);
}
