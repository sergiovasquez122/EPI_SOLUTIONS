#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

bool isPalindrome(const string& s){
    int i = 0, l = s.size() - 1;
    while(i < l){
      if(s[i++] != s[l--]) return false;
    }
    return true;
}

void helper(vector<vector<string>>& result, vector<string>& partial, const string& text, int begin){
    if(begin == text.size()){
        result.push_back(partial);
        return;
    }
    for(int i = begin + 1;i <= text.size();++i){
        string s = text.substr(begin, i - begin);
        if(isPalindrome(s)){
            partial.push_back(s);
            helper(result, partial, text, i);
            partial.pop_back();
        }
    }
}

vector<vector<string>> PalindromeDecompositions(const string& text) {
    vector<vector<string>> result;
    vector<string> partial;
    helper(result, partial, text, 0);
    return result;
}

bool Comp(vector<vector<string>> expected, vector<vector<string>> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"text"};
  return GenericTestMain(args, "enumerate_palindromic_decompositions.cc",
                         "enumerate_palindromic_decompositions.tsv",
                         &PalindromeDecompositions, &Comp, param_names);
}
