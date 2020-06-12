#include <string>
#include "test_framework/generic_test.h"
using std::string;
using std::to_string;

string iteration(const string& s){
    string result;
    for(int i = 0;i < s.size();++i){
        int counter = 1;
        while(i + 1 < s.size() && s[i] == s[i + 1]) i++, counter++;
        result += to_string(counter) + s[i];
    }
    return result;
}

string LookAndSay(int n) {
    string s = "1";
    for(int i = 1;i < n;++i){
        s = iteration(s); 
    }
    return s;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
