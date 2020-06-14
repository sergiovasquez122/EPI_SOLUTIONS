#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
    int low = 0, hi = A.size() - 1;
    int ret = -1;
    while( low <= hi ){
        int mid = (low + hi) / 2;
        if(A[mid] < k) {
            low = mid + 1;
        } else if(A[mid] > k){
            hi = mid - 1;
        } else {
            ret = mid;
            hi = mid - 1;
        }
    }
    return ret;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
