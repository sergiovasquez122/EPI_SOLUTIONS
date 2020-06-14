#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void generate_row(vector<vector<int>>& rows){
    vector<int> next_rows = {1};
    for(int i = 1;i < rows.back().size();++i){
        next_rows.push_back(rows.back()[i - 1] + rows.back()[i]);
    }
    next_rows.push_back(1);
    rows.push_back(next_rows);
}

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
    if(num_rows == 0){
        return {};
    }
    if(num_rows == 1){
      return {{1}};
    }

    if(num_rows == 2){
        return {{1}, {1,1}};
    }

    vector<vector<int>> rows = {{1}, {1, 1}};
    for(int i = 2; i < num_rows;++i){
        generate_row(rows);
    }
    return rows;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_rows"};
  return GenericTestMain(args, "pascal_triangle.cc", "pascal_triangle.tsv",
                         &GeneratePascalTriangle, DefaultComparator{},
                         param_names);
}
