#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::begin;
using std::end;
using std::vector;
using std::deque;

bool validPlacement(const vector<vector<int>>& A, int i, int j, int value){
    for(int row = 0;row < A.size();++row){
        if(A[row][j] == value){
            return false;
        }
    }

    for(int col = 0;col < A.size();++col){
        if(A[i][col] == value){
            return false;
        }
    }

    int region_size = sqrt(A.size());
    int ith = i / region_size;
    int jth = j / region_size;
    for(int k = 0;k < region_size;++k){
        for(int p = 0;p < region_size;++p){
            if(value == A[region_size * ith + k][region_size * jth + p]){
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<int>>& A, int i, int j){
    if(j == A.size()){
        j = 0;
        if(++i == A.size()){
            return true;
        }
    }

    if(A[i][j] != 0){
        return helper(A, i, j + 1);
    }

    for(int value = 1; value <= 9;++value){
        if(validPlacement(A, i, j, value)){
            A[i][j] = value;
            if(helper(A, i, j + 1)){
                return true;
            }
        }
    }
    A[i][j] = 0;
    return false;
}

bool SolveSudoku(vector<vector<int>>* partial_assignment) {
    vector<vector<int>>& sudoku = *partial_assignment;
    return helper(sudoku, 0, 0);
}

vector<int> GatherColumn(const vector<vector<int>>& data, size_t i) {
  vector<int> result;
  for (auto& row : data) {
    result.push_back(row[i]);
  }
  return result;
}

vector<int> GatherSquareBlock(const vector<vector<int>>& data,
                              size_t block_size, size_t n) {
  vector<int> result;
  size_t block_x = n % block_size;
  size_t block_y = n / block_size;
  for (size_t i = block_x * block_size; i < (block_x + 1) * block_size; i++) {
    for (size_t j = block_y * block_size; j < (block_y + 1) * block_size; j++) {
      result.push_back(data[i][j]);
    }
  }

  return result;
}

void AssertUniqueSeq(const vector<int>& seq) {
  vector<bool> seen(seq.size(), false);
  for (auto& x : seq) {
    if (x == 0) {
      throw TestFailure("Cell left uninitialized");
    }
    if (x < 0 || x > seq.size()) {
      throw TestFailure("Cell value out of range");
    }
    if (seen[x - 1]) {
      throw TestFailure("Duplicate value in section");
    }
    seen[x - 1] = true;
  }
}

void SolveSudokuWrapper(TimedExecutor& executor,
                        const vector<vector<int>>& partial_assignment) {
  vector<vector<int>> solved = partial_assignment;

  executor.Run([&] { SolveSudoku(&solved); });

  if (!std::equal(begin(partial_assignment), end(partial_assignment),
                  begin(solved), end(solved), [](auto br, auto cr) {
                    return std::equal(begin(br), end(br), begin(cr), end(cr),
                                      [](int bcell, int ccell) {
                                        return bcell == 0 || bcell == ccell;
                                      });
                  }))
    throw TestFailure("Initial cell assignment has been changed");

  auto block_size = static_cast<size_t>(sqrt(solved.size()));

  for (size_t i = 0; i < solved.size(); i++) {
    AssertUniqueSeq(solved[i]);
    AssertUniqueSeq(GatherColumn(solved, i));
    AssertUniqueSeq(GatherSquareBlock(solved, block_size, i));
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "partial_assignment"};
  return GenericTestMain(args, "sudoku_solve.cc", "sudoku_solve.tsv",
                         &SolveSudokuWrapper, DefaultComparator{}, param_names);
}
