#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;
using std::min;
using std::min_element;

int MinimumPathWeight(const vector<vector<int>>& triangle) {
    if(triangle.empty()){
      return 0;
    }

    vector<int> current_row(triangle.front());
    for(int i = 1;i < triangle.size();++i){
        vector<int> next_row(triangle[i]);
        next_row.front() += current_row.front();
        for(int k = 1;k < next_row.size() - 1;++k){
            next_row[k] += min(current_row[k - 1], current_row[k]);
        }
        next_row.back() += current_row.back();
        std::swap(current_row, next_row);
    }
    return *min_element(current_row.begin(), current_row.end());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"triangle"};
  return GenericTestMain(args, "minimum_weight_path_in_a_triangle.cc",
                         "minimum_weight_path_in_a_triangle.tsv",
                         &MinimumPathWeight, DefaultComparator{}, param_names);
}
