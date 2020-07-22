#include <vector>

#include "test_framework/generic_test.h"
using std::vector;


void helper(vector<vector<int>>& A, const vector<int>& input_set,vector<int>& partial,int begin){
    A.push_back(partial);
    for(int i = begin;i < input_set.size();++i){
        partial.push_back(input_set[i]);
        helper(A, input_set, partial, i + 1);
        partial.pop_back();
    }
}

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
    vector<vector<int>> result;
    vector<int> partial;
    helper(result, input_set, partial, 0);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input_set"};
  return GenericTestMain(args, "power_set.cc", "power_set.tsv",
                         &GeneratePowerSet, UnorderedComparator{}, param_names);
}
