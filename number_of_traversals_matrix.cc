#include "test_framework/generic_test.h"
#include <vector>

using std::vector;


int NumberOfWays(int n, int m) {
  vector<vector<int>> memo(n, vector<int>(m, 0));
  for(int i = 0;i < n;++i) 
    memo[i][0] = 1;
  
  for(int i = 0;i < m;++i)
    memo[0][i] = 1;
  
  for(int i = 1;i < n;++i){
    for(int j = 1;j < m;++j){
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
    }
  }
  return memo[n - 1][m - 1];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "m"};
  return GenericTestMain(args, "number_of_traversals_matrix.cc",
                         "number_of_traversals_matrix.tsv", &NumberOfWays,
                         DefaultComparator{}, param_names);
}
