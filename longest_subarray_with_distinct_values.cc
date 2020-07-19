#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::vector;
using std::unordered_map;

int LongestSubarrayWithDistinctEntries(const vector<int>& A) {
    unordered_map<int ,int> dup_idx;
    size_t sub_array_idx = 0, result = 0;
    for(int i = 0;i < A.size();++i){
        auto it = dup_idx.emplace(A[i], i);
        if(!it.second){
            if(it.first->second >= sub_array_idx){
                result = std::max(result, i - sub_array_idx);
                sub_array_idx = it.first->second + 1;
            }
            it.first->second = i;
        }
    }
    result = std::max(result, A.size() - sub_array_idx);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "longest_subarray_with_distinct_values.cc",
                         "longest_subarray_with_distinct_values.tsv",
                         &LongestSubarrayWithDistinctEntries,
                         DefaultComparator{}, param_names);
}
