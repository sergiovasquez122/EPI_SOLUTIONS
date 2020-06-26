#include <stdexcept>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::vector;

bool feasible(vector<vector<char>>& board, int x, int y, char ch){
    return x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == ch;
}

void dfs(vector<vector<char>>& board, int x, int y, char old_color, char new_color){
    if(!feasible(board, x, y, old_color)){
        return;
    }

    board[x][y] = new_color;
    const vector<vector<int>> shifts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(auto& shift : shifts){
        dfs(board, x + shift[0], y + shift[1], old_color, new_color);
    }
}

void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
    vector<vector<char>>& board = *board_ptr;
    if(board.empty()){
        return;
    }
    for(int i = 0;i < board.size();++i){
        if(board[i][0] == 'W'){
            dfs(board, i, 0, 'W', 'S');
        }
        if(board[i][board[i].size() - 1] == 'W'){
            dfs(board, i,  board[i].size() - 1, 'W', 'S');
        }
    }

    for(int j = 0;j < board.front().size();++j){
        if(board[0][j] == 'W'){
            dfs(board, 0, j, 'W','S');
        } if(board[board.size() - 1][j] == 'W'){
            dfs(board, board.size() - 1, j, 'W','S');
        }
    }

    for(int i = 0;i < board.size();++i){
        for(int j = 0;j < board.front().size();++j){
            board[i][j] = (board[i][j] != 'S' ? 'B' : 'W');
        }
    }
}

vector<vector<string>> FillSurroundedRegionsWrapper(
    TimedExecutor& executor, vector<vector<string>> board) {
  vector<vector<char>> char_vector;
  char_vector.resize(board.size());
  for (int i = 0; i < board.size(); i++) {
    for (const string& s : board[i]) {
      if (s.size() != 1) {
        throw std::runtime_error("String size is not 1");
      }
      char_vector[i].push_back(s[0]);
    }
  }

  executor.Run([&] { FillSurroundedRegions(&char_vector); });

  board.clear();
  board.resize(char_vector.size(), {});
  for (int i = 0; i < board.size(); i++) {
    for (char c : char_vector[i]) {
      board[i].emplace_back(1, c);
    }
  }

  return board;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "board"};
  return GenericTestMain(
      args, "matrix_enclosed_regions.cc", "matrix_enclosed_regions.tsv",
      &FillSurroundedRegionsWrapper, DefaultComparator{}, param_names);
}
