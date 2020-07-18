#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void RookAttack(vector<vector<int>>* A_ptr) {
    vector<vector<int>>& A = *A_ptr;

    bool first_row = false;
    for(int col = 0;col < A[0].size();++col){
        if(!A[0][col]){
            first_row = true;
            break;
        }
    }
    bool first_col = false;
    for(int row = 0;row < A.size();++row){
        if(!A[row][0]){
            first_col = true;
            break;
        }
    }

    for(int row = 1;row < A.size(); ++row){
        for(int col = 1;col < A[0].size();++col){
            if(!A[row][col]){
                A[0][col] = false;
                A[row][0] = false;
            }
        }
    }

    for(int row = 1;row < A.size();++row){
        if(!A[row][0]){
            for(int col = 1;col < A[0].size();++col){
                A[row][col] = false;
            }
        }
    }

    for(int col = 1;col < A[0].size();++col){
        if(!A[0][col]){
            for(int row = 1;row < A.size();++row){
                A[row][col] = false;
            }
        }
    }

    if(first_row){
        for(int col = 0;col < A[0].size();++col){
            A[0][col] = false;
        }
    }

    if(first_col){
        for(int row = 0;row < A.size();++row){
            A[row][0] = false;
        }
    }
}

vector<vector<int>> RookAttackWrapper(vector<vector<int>> A) {
  vector<vector<int>> a_copy = A;
  RookAttack(&a_copy);
  return a_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "rook_attack.cc", "rook_attack.tsv",
                         &RookAttackWrapper, DefaultComparator{}, param_names);
}
