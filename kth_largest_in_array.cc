#include <vector>
#include <random>
#include "test_framework/generic_test.h"
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

int partition(vector<int>& A, int left, int right, int pivot_idx){
    int pivot_value = A[pivot_idx];
    std::swap(A[pivot_idx], A[right]);
    int new_pivot_idx = left;
    for(int i = left;i < right;++i){
      if(A[i] < pivot_value){
          std::swap(A[i], A[new_pivot_idx++]);
      }
    }
    std::swap(A[new_pivot_idx], A[right]);
    return new_pivot_idx;
}

int findKth(int k, vector<int>* A_ptr){
    vector<int>& A = *A_ptr;
    default_random_engine gen((std::random_device())());
    int left = 0, right = A.size() - 1;
    while(left <= right){
        int pivot = uniform_int_distribution<int>{left, right}(gen);
        int new_pivot = partition(A, left, right, pivot);
        if(k - 1 == new_pivot){
            return A[new_pivot];
        } else if(k - 1 < new_pivot){
            right = new_pivot - 1;
        } else {
            left = new_pivot + 1;
        }
    }
}

int FindKthLargest(int k, vector<int>* A_ptr) {
    return findKth(A_ptr->size() - k + 1, A_ptr);
}

int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "A"};
  return GenericTestMain(args, "kth_largest_in_array.cc",
                         "kth_largest_in_array.tsv", &FindKthLargestWrapper,
                         DefaultComparator{}, param_names);
}
