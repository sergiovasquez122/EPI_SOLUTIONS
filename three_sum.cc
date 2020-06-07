#include <vector>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::vector;
using std::unordered_set;

bool hasTwoSum(const vector<int> &A, int target){
    int low_idx = 0, hi_idx = A.size() - 1;
    while(low_idx <= hi_idx){
        if(A[low_idx] + A[hi_idx] < target){
            low_idx++;
       } else if(A[low_idx] + A[hi_idx] > target){
            hi_idx--;
        } else{
            return true;
        }
    }
    return false;
}


bool HasThreeSum(vector<int> A, int t) {
    sort(A.begin(), A.end());
    for(int e : A){
        if(hasTwoSum(A, t - e)){
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
