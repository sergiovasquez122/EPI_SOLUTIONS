#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::vector;
using std::unordered_set;

bool HasTwoSum(const vector<int>& A, int t) {
  unordered_set<int> elements;
  for(int x : A){
    elements.insert(x);
  }
  
  for(int y : A){
    if(elements.count(t - y)){
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "two_sum.cc", "two_sum.tsv", &HasTwoSum,
                         DefaultComparator{}, param_names);
}
