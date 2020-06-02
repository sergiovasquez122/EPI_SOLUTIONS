#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;
string Decoding(const string &s) {
    string result;
    int count = 0;
    for(int i = 0;i < s.size();++i){
        if(isdigit(s[i])){
            count = count * 10 + (s[i] - '0');
        } else{
            result.append(count, s[i]);
            count = 0;
        }
    }
    return result;
}

string Encoding(const string &s) {
    string result;
    int count = 1;
    for(int i = 1;i <= s.size();++i){
        if(i == s.size() || s[i] != s[i - 1]){
            result += std::to_string(count) + s[i - 1];
            count = 1;
        } else {
            count++;
        }
    }
    return result;
}

void RleTester(const string &encoded, const string &decoded) {
  if (Decoding(encoded) != decoded) {
    throw TestFailure("Decoding failed");
  }
  if (Encoding(decoded) != encoded) {
    throw TestFailure("Encoding failed");
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"encoded", "decoded"};
  return GenericTestMain(args, "run_length_compression.cc",
                         "run_length_compression.tsv", &RleTester,
                         DefaultComparator{}, param_names);
}
