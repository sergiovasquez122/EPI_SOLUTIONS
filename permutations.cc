#include <vector>

#include "test_framework/generic_test.h"
using std::vector;


void helper(vector<vector<int>>& result, vector<int>& perm, int begin){
    if(begin == perm.size() - 1) {
        result.push_back(perm);
    } else {
        for(int i = begin;i < perm.size();++i){
            std::swap(perm[begin], perm[i]);
            helper(result, perm, begin + 1);
            std::swap(perm[begin], perm[i]);
        }
    }
}

vector<vector<int>> Permutations(vector<int> A) {
    vector<vector<int>> result;
    helper(result, A, 0);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "permutations.cc", "permutations.tsv",
                         &Permutations, UnorderedComparator{}, param_names);
}
