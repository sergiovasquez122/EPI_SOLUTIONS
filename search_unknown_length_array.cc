#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int get(const vector<int>& A, int idx){
    if(idx < A.size()){
        return A[idx];
    }
    return std::numeric_limits<int>::max();
}

int BinarySearchUnknownLength(const vector<int>& A, int k) {
    int start = 0, end = 1;
    while(end < A.size() && get(A, end) < k){
        end *= 2;
    }
    while(start <= end){
        int mid = (end + start) / 2;
        if(get(A, mid) < k){
            start = mid + 1;
        } else if(get(A, mid) > k){
            end = mid - 1;
        } else{
            return mid;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(
      args, "search_unknown_length_array.cc", "search_unknown_length_array.tsv",
      &BinarySearchUnknownLength, DefaultComparator{}, param_names);
}
