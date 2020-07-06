#include <vector>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::vector;
using std::unordered_set;

bool TestCollatzConjecture(int n) {
    unordered_set<long>  verified_numbers = {1, 2};
    for(int i = 3;i <= n;i+=2){
        unordered_set<long> sequence;
        long val = i;
        while(val >= 1){
            if(sequence.insert(val).second == false){
                return true;
            }
            if(val % 2){
                if(verified_numbers.insert(val).second == false){
                    break;
                }
                if(val < i){
                    return false;
                }
                val = 3 * val + 1;
            } else {
                val /= 2;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "collatz_checker.cc", "collatz_checker.tsv",
                         &TestCollatzConjecture, DefaultComparator{},
                         param_names);
}
