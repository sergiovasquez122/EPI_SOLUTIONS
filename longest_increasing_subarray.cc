#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

struct Subarray {
  int start = 0, end = 0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& A) {
    Subarray result{0, 0};
    int max_length = 1;
    int current_length = 1;
    int starting_idx = 0;
    for(int i = 1;i < A.size();i++){
        if(A[i] > A[i - 1]){
            current_length++;
        } else {
            if(max_length < current_length){
                max_length = current_length;
                result = {starting_idx, i - 1};
            }
            current_length = 1;
            starting_idx = i;
        }
    }
    if(max_length < current_length){
        int end = A.size() - 1;
        result = {starting_idx, end};
    }
    return result;
}

int FindLongestIncreasingSubarrayWrapper(const vector<int>& A) {
  Subarray result = FindLongestIncreasingSubarray(A);
  return result.end - result.start + 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "longest_increasing_subarray.cc", "longest_increasing_subarray.tsv",
      &FindLongestIncreasingSubarrayWrapper, DefaultComparator{}, param_names);
}
