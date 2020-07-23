#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool is_valid(vector<int>& partial, int candidate, int row){
    for(int i = 0;i <= row - 1;++i){
        if(candidate == partial[i] || std::abs(candidate - partial[i]) == row - i){
            return false;
        }
    }
    return true;
}

void helper(vector<vector<int>>& result, vector<int>& partial, int row, int n){
    if(row == n){
        result.push_back(partial);
        return;
    }
    for(int i = 0;i < n;++i){
        if(is_valid(partial, i, row)){
            partial.push_back(i);
            helper(result, partial, row + 1, n);
            partial.pop_back();
        }
    }
}

vector<vector<int>> NQueens(int n) {
    vector<vector<int>> result;
    vector<int> partial;
    helper(result, partial, 0, n);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "n_queens.cc", "n_queens.tsv", &NQueens,
                         UnorderedComparator{}, param_names);
}
