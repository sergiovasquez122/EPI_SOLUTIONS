#include <string>
#include <vector>
#include <array>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
using std::array;
const int kNum = 10;
const array<string, kNum> kmapping = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void helper(vector<string>& result, string& current, const string& phone_number, int idx){
    if(idx == phone_number.size()){
        result.push_back(current);
    } else {
        int k = phone_number[idx] - '0';
        for(char c : kmapping[k]){
            current.push_back(c);
            helper(result, current, phone_number, idx + 1);
            current.pop_back();
        }
    }
}

vector<string> PhoneMnemonic(const string& phone_number) {
    vector<string> result;
    string partial;
    helper(result, partial, phone_number, 0);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"phone_number"};
  return GenericTestMain(args, "phone_number_mnemonic.cc",
                         "phone_number_mnemonic.tsv", &PhoneMnemonic,
                         UnorderedComparator{}, param_names);
}
