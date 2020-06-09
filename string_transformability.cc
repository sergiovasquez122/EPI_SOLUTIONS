#include <string>
#include <unordered_set>
#include <queue>
#include "test_framework/generic_test.h"

using std::string;
using std::unordered_set;
using std::queue;

struct string_with_length{
    string s;
    int l;
    string_with_length(string s, int l) : s(std::move(s)), l(l) {}
};

int TransformString(unordered_set<string> D, const string& s, const string& t) {
  queue<string_with_length> on_queue;
  on_queue.push({s, 0});
  while(!on_queue.empty()){
      auto curr = on_queue.front();
      on_queue.pop();

      if(curr.s == t){
        return curr.l;
      }

      for(int i = 0;i < curr.s.size();++i){
          char original = curr.s[i];
          for(char c = 'a';c <= 'z';++c){
              curr.s[i] = c;
              auto it = D.find(curr.s);
              if(it != D.end()){
                  D.erase(it);
                  on_queue.push({curr.s, curr.l + 1});
              }
          }
          curr.s[i] = original;
      }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}
