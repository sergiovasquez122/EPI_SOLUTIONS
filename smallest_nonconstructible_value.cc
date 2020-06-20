#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int SmallestNonconstructibleValue(vector<int> A) {
    sort(A.begin(), A.end());
    int max_constructible = 0;
    for(int a : A){
        if(max_constructible + 1 < a){
            break;
        }
        max_constructible += a;
    }
    return max_constructible + 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "smallest_nonconstructible_value.cc",
                         "smallest_nonconstructible_value.tsv",
                         &SmallestNonconstructibleValue, DefaultComparator{},
                         param_names);
}
