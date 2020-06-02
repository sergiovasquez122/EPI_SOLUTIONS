#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
    string result;
    bool isNegative = x < 0;
    do {
        int val =  abs(x % 10);
        result += '0' + val;
        x /= 10;
    } while(x);

    if(isNegative){
        result.push_back('-');
    }

    return {result.rbegin(), result.rend()};
}
int StringToInt(const string& s) {
    int result = 0;

    for(int i = s[0] == '-' || s[0] == '+' ? 1 : 0;i < s.size();++i){
        result = result * 10 + (s[i] - '0');
    }

    return s[0] == '-' ?  -result : result;
}
void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
