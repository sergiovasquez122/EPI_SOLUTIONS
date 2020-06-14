#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;
using std::binary_search;

vector<int> solution_1(const vector<int>& A, const vector<int>& B){
    vector<int> result;
    for(int i = 0;i < A.size();++i){
        if(i == 0 || A[i - 1] != A[i]){
            if(binary_search(B.begin(), B.end(), A[i])){
                result.push_back(A[i]);
            }
        }
    }
    return result;
}

vector<int> solution_2(const vector<int>& A, const vector<int>& B){
    vector<int> result;
    int a = 0, b = 0;
    while(a < A.size() && b < B.size()){
        if((A[a] == B[b]) && (a == 0 || A[a - 1] != A[a])){
            result.push_back(A[a]);
            a++, b++;
        } else if(A[a] < B[b]){
            a++;
        } else {
            b++;
        }
    }
    return result;
}

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
    return solution_2(A, B);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
