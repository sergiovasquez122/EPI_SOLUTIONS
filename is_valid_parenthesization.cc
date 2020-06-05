#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;
using std::stack;
using std::unordered_map;

bool IsWellFormed(const string& s) {
  unordered_map<char,char> braces = {{'{', '}'}, {'(', ')'} , {'[' , ']'}};
  stack<char> left_parens;
  for(char c : s){
    if(braces.count(c)){
      left_parens.push(c);
    } else if(!braces.count(c) && left_parens.empty()){
      return false;
    } else if(braces[left_parens.top()] != c){
      return false;
    } else if(braces[left_parens.top()] == c){
      left_parens.pop();
    } else {
      return false;
    }
  }
  return left_parens.empty();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_valid_parenthesization.cc",
                         "is_valid_parenthesization.tsv", &IsWellFormed,
                         DefaultComparator{}, param_names);
}
