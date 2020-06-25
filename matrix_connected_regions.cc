#include <deque>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::deque;
using std::vector;

bool feasible(vector<deque<bool>>& image, int x, int y, int color){
  return x >= 0 && x < image.size() && y >= 0 && y < image.size() && image[x][y] == color; 
}

void dfs(vector<deque<bool>>& image, int x, int y, int color){
    if(!feasible(image, x, y, color)){
        return;
    }
    image[x][y] = !color;
    
    const vector<vector<int>> shifts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for(auto& shift : shifts){
        dfs(image, x + shift[0], y + shift[1], color);
    }
}

void FlipColor(int x, int y, vector<deque<bool>>* image_ptr) {
    vector<deque<bool>>& image = *image_ptr;
    dfs(image, x, y, image[x][y]);
}

vector<vector<int>> FlipColorWrapper(TimedExecutor& executor, int x, int y,
                                     vector<vector<int>> image) {
  vector<deque<bool>> b;
  b.reserve(image.size());
  for (const vector<int>& row : image) {
    deque<bool> tmp;
    tmp.resize(row.size());
    for (int i = 0; i < row.size(); ++i) {
      tmp[i] = static_cast<bool>(row[i]);
    }
    b.push_back(tmp);
  }

  executor.Run([&] { FlipColor(x, y, &b); });

  image.resize(b.size());

  for (int i = 0; i < image.size(); ++i) {
    image[i].resize(b.size());
    for (int j = 0; j < image[i].size(); ++j) {
      image[i][j] = b[i][j];
    }
  }
  return image;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "x", "y", "image"};
  return GenericTestMain(args, "matrix_connected_regions.cc", "painting.tsv",
                         &FlipColorWrapper, DefaultComparator{}, param_names);
}
