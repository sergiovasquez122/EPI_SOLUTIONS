#include <string>
#include <stack>
#include <sstream>
#include "test_framework/generic_test.h"

using std::string;
using std::stack;
using std::stringstream;
int Evaluate(const string& expression) {
  // TODO - you fill in here.
  const char delimiter = ',';
  stack<int> intermediate_result;
  stringstream ss(expression);
  string token;
  while(getline(ss, token, delimiter)){
    if(token == "+" || token == "-" || token == "*" || token == "/"){
        int y = intermediate_result.top();
        intermediate_result.pop();
        int x = intermediate_result.top();
        intermediate_result.pop();

        switch(token[0]){
          case '+': intermediate_result.push(x + y);
              break;
          case '-': intermediate_result.push(x - y);
              break;
            case '*': intermediate_result.push(x * y);
            break;
            case '/': intermediate_result.push(x / y);
            break;
        }
    } else {
        intermediate_result.push(std::stoi(token));
    }
  }
  return intermediate_result.top();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.cc", "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
