#include <memory>

#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;
using std::make_unique;

unique_ptr<BstNode<int>> helper(const vector<int>& preorder_sequence, int& write_idx, int upper_bound){
    if(write_idx == preorder_sequence.size() || preorder_sequence[write_idx] > upper_bound) {
        return nullptr;
    }
    int value = preorder_sequence[write_idx++];
    return make_unique<BstNode<int>>(BstNode<int>{value, helper(preorder_sequence, write_idx, value),
                                                  helper(preorder_sequence, write_idx, upper_bound)});
}

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
    int write_idx = 0;
    return helper(preorder_sequence, write_idx, std::numeric_limits<int>::max());
}



int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder_sequence"};
  return GenericTestMain(args, "bst_from_preorder.cc", "bst_from_preorder.tsv",
                         &RebuildBSTFromPreorder, DefaultComparator{},
                         param_names);
}
