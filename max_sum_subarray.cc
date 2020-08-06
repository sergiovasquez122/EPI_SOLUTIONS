#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int FindMaximumSubarray(const vector<int>& A) {
  if(A.empty()) return 0;
  vector<int> elements(A.size(), 0);
  elements[0] = A[0];
  int result = std::max(0, elements[0]);
  for(int i = 1;i < A.size();i++){
    elements[i] = A[i] + (elements[i - 1] > 0 ? elements[i - 1] : 0);
    result = std::max(result, elements[i]);
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_sum_subarray.cc", "max_sum_subarray.tsv",
                         &FindMaximumSubarray, DefaultComparator{},
                         param_names);
}
