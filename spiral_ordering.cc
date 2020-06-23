#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix) {
    int L = 0, R = square_matrix.size() - 1;
    int U = 0, B = square_matrix.size() - 1;
    int dir = 0;
    vector<int> result;
    while(L <= R &&  U <= B){
        if(dir == 0){
            for(int i = L;i <= R;++i){
                result.push_back(square_matrix[U][i]);
            }
             U++;
        } else if(dir == 1){
            for(int i = U;i <= B;++i){
                result.push_back(square_matrix[i][R]);
            }
            R--;
        } else if(dir == 2){
            for(int i = R;i >= L;--i){
                result.push_back(square_matrix[B][i]);
            }
            B--;
        } else {
            for(int i = B; i>= U;--i){
                result.push_back(square_matrix[i][L]);
            }
            L++;
        }
        dir = (dir + 1) % 4;
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "spiral_ordering.cc", "spiral_ordering.tsv",
                         &MatrixInSpiralOrder, DefaultComparator{},
                         param_names);
}
