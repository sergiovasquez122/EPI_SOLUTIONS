#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;
using std::unordered_map;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
    unordered_map<int, int> freq_count;
    for(char c : letter_text){
        ++freq_count[c];
    }

    for(char c : magazine_text){
        auto iter = freq_count.find(c);
        if(iter != freq_count.end()){
            if(--iter->second == 0){
                freq_count.erase(iter);
                if(freq_count.empty()){
                    break;
                }
            }
        }
    }
    return freq_count.empty();
}

//Average running time:  330 us
//Median running time:    29 us
//
int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  return GenericTestMain(args, "is_anonymous_letter_constructible.cc",
                         "is_anonymous_letter_constructible.tsv",
                         &IsLetterConstructibleFromMagazine,
                         DefaultComparator{}, param_names);
}
