#include <string>
#include <algorithm>
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::reverse;

void ReverseWords(string* s) {
    reverse(s->begin(),s->end());
    int begin = 0;
    int end = 0;
    while((end = s->find(' ', begin)) != string::npos){
        reverse(s->begin() + begin, s->begin() + end);
        begin = end + 1;
    }
    reverse(s->begin() + begin, s->end());
}

string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  executor.Run([&] { ReverseWords(&s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}
