#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool helper(BinaryTreeNode<int>* p1, BinaryTreeNode<int>* p2){
  if(!p1 && !p2) return true;
  if((p1 && !p2) || !p1) return false;
  return p1->data == p2->data && helper(p1->left.get(), p2->right.get()) && helper(p1->right.get(), p2->left.get());
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
    return helper(tree.get(), tree.get());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
