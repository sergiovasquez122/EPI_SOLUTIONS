#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
    vector<vector<int>> result;
    for(int i = 0;i < num_rows;++i){
        vector<int> current_row;
        for(int j = 0;j <= i;++j){
            current_row.push_back(0 < j && j < i? result.back()[j] + result.back()[j - 1] : 1);
        }
        result.push_back(current_row);
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_rows"};
  return GenericTestMain(args, "pascal_triangle.cc", "pascal_triangle.tsv",
                         &GeneratePascalTriangle, DefaultComparator{},
                         param_names);
}
