#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"

using std::string;
using std::unordered_map;

/**
 * Solution is O(n) as we walk through the entire input
 * The space is constant
 */
int RomanToInteger(const string& s) {
    if(s.empty()) return 0;
    unordered_map<char, int> roman_to_int_mapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = roman_to_int_mapping[s.back()];
    for(int i = s.size() - 2;i >= 0;i--){
        if(roman_to_int_mapping[s[i]] < roman_to_int_mapping[s[i + 1]]){
            result -= roman_to_int_mapping[s[i]];
        } else {
            result += roman_to_int_mapping[s[i]];
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "roman_to_integer.cc", "roman_to_integer.tsv",
                         &RomanToInteger, DefaultComparator{}, param_names);
}
