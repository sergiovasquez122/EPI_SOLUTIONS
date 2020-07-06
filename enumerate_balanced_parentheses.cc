#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

void helper(vector<string>& result, string& partial, int n, int left_paren, int right_paren){
    if(partial.size() == n * 2){
        result.push_back(partial);
        return;
    }

    if(left_paren < n){
        partial.push_back('(');
        helper(result, partial, n, left_paren + 1, right_paren);
        partial.pop_back();
    }

    if(right_paren < left_paren){
        partial.push_back(')');
        helper(result, partial, n, left_paren, right_paren + 1);
        partial.pop_back();
    }

}

vector<string> GenerateBalancedParentheses(int num_pairs) {
    vector<string> result;
    string partial;
    helper(result, partial, num_pairs, 0, 0);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_pairs"};
  return GenericTestMain(args, "enumerate_balanced_parentheses.cc",
                         "enumerate_balanced_parentheses.tsv",
                         &GenerateBalancedParentheses, UnorderedComparator{},
                         param_names);
}
