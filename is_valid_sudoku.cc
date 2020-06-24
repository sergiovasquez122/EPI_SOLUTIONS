#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using std::deque;

bool has_dups(const vector<vector<int>>& A, int starting_row, int end_row, int starting_col, int end_col){
    deque<bool> elements(A.size() + 1, false);
    for(int i = starting_row;i < end_row;++i){
        for(int j = starting_col;j < end_col;++j){
            if(A[i][j] != 0 && elements[A[i][j]]){
                return true;
            }
            elements[A[i][j]] = true;
        }
    }
    return false;
}

bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
    for(int i = 0;i < partial_assignment.size();++i){
        if(has_dups(partial_assignment, i, i + 1, 0, partial_assignment.size())){
            return false;
        }
    }

    for(int i = 0;i < partial_assignment.size();++i){
        if(has_dups(partial_assignment, 0, partial_assignment.size(), i, i + 1)){
            return false;
        }
    }

    int region_size = sqrt(partial_assignment.size());
    for(int i = 0;i < region_size;++i){
        for(int j = 0;j < region_size;++j){
            if(has_dups(partial_assignment, region_size * i, (i + 1) * region_size, region_size * j, (j + 1) * region_size)){
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}
