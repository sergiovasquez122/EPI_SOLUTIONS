#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

bool isValid(const string& s){
   if(s.size() > 3){
    return false;
   }

   if(s.front() == '0' && s.size() > 1){
       return false;
   }

   int val = std::stoi(s);

   return 0 <= val && val <= 255;
}

vector<string> GetValidIpAddress(const string& s) {
    vector<string> result;
    for(size_t i = 1;i < s.size() && i < 4;++i){
        string s1 = s.substr(0, i);
        if(isValid(s1)){
            for(size_t j = 1;i + j < s.size() && j < 4;++j){
                string s2 = s.substr(i, j);
                if(isValid(s2)){
                    for(size_t k = 1;i + j + k < s.size() && k < 4;++k){
                        string s3 = s.substr(i + j, k);
                        string s4 = s.substr(i + j + k);
                        if(isValid(s3) && isValid(s4)){
                            result.emplace_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "valid_ip_addresses.cc",
                         "valid_ip_addresses.tsv", &GetValidIpAddress,
                         UnorderedComparator{}, param_names);
}
