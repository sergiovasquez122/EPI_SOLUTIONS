#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
using std::unordered_map;

int FindNearestRepetition(const vector<string>& paragraph) {
    unordered_map<string, int> entries;
    int result = std::numeric_limits<int>::max();
    for(int i = 0;i < paragraph.size();++i){
        auto it = entries.find(paragraph[i]);
        if(it != entries.end()){
            result = std::min(result, i - it->second);
        }
        entries[paragraph[i]] = i;
    }
    return result == std::numeric_limits<int>::max() ? -1 : result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"paragraph"};
  return GenericTestMain(args, "nearest_repeated_entries.cc",
                         "nearest_repeated_entries.tsv", &FindNearestRepetition,
                         DefaultComparator{}, param_names);
}
