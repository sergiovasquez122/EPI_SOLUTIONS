#include <vector>
#include <unordered_map>
#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
using std::vector;
using std::unordered_map;
using std::make_unique;

unique_ptr<BinaryTreeNode<int>> helper(const vector<int>& preorder, unordered_map<int, int>& mapping,
        int& preorder_idx, int lower_bound, int upper_bound){
    if((preorder_idx == preorder.size()) || (upper_bound < lower_bound)){
      return nullptr;
    }

    int val = preorder[preorder_idx++];
    int bound = mapping[val];
    auto left = helper(preorder, mapping, preorder_idx, lower_bound, bound - 1);
    auto right = helper(preorder, mapping, preorder_idx, bound + 1, upper_bound);
    return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{val, std::move(left), std::move(right)});
}

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {
    unordered_map<int, int> mapping;
    for(int i = 0;i < inorder.size();++i){
        mapping[inorder[i]] = i;
    }
    int preorder_idx = 0;
    return helper(preorder, mapping, preorder_idx, 0, inorder.size() - 1);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder", "inorder"};
  return GenericTestMain(
      args, "tree_from_preorder_inorder.cc", "tree_from_preorder_inorder.tsv",
      &BinaryTreeFromPreorderInorder, DefaultComparator{}, param_names);
}
