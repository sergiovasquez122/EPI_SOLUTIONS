#include <string>
#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
using std::unordered_map;

bool isValid(const string& s, const unordered_map<string,int>& freq_count, int unit_size){
   unordered_map<string, int> curr_count;
   for(int i = 0;i * unit_size < s.length();++i){
       string temp = s.substr(i * unit_size, unit_size);
       if(!freq_count.count(temp)){
           return false;
       }
       ++curr_count[temp];
       if(curr_count[temp] > freq_count.at(temp)){
           return false;
       }
   }
   return true;
}

// The time complexity is O(N*n*m)
// where N is the sentence length
// m is the number of words
// n is the length of each word
vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
    unordered_map<string, int> freq_count;
    for(auto& w : words){
        ++freq_count[w];
    }
    int unit_size = words.front().size();
    int length = words.size() * unit_size;
    vector<int> result;
    for(int i = 0;i + length <= s.length();++i){
        string temp = s.substr(i, length);
        if(isValid(temp, freq_count, unit_size)){
            result.push_back(i);
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s", "words"};
  return GenericTestMain(args, "string_decompositions_into_dictionary_words.cc",
                         "string_decompositions_into_dictionary_words.tsv",
                         &FindAllSubstrings, DefaultComparator{}, param_names);
}
