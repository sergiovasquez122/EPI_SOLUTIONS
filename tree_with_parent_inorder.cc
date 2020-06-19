#include <vector>

#include "binary_tree_with_parent_prototype.h"
#include "test_framework/generic_test.h"
using std::vector;

BinaryTreeNode<int>* findMin(const unique_ptr<BinaryTreeNode<int>>& node){
  auto iter = node.get();
  while(iter && iter->left){
    iter = iter->left.get();
  }
  return iter;
}

BinaryTreeNode<int>* FindSuccessor(
        BinaryTreeNode<int>*& node) {
  if(node->right){
    return findMin(node->right);
  }

  auto iter = node;
  while(iter->parent != nullptr && iter == iter->parent->right.get()){
    iter = iter->parent;
  }
  return iter->parent;
}

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if(tree == nullptr){
      return {};
    }

    vector<int> result;
    auto iter = findMin(tree);
    while(iter){
        result.push_back(iter->data);
        iter = FindSuccessor(iter);
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_with_parent_inorder.cc",
                         "tree_with_parent_inorder.tsv", &InorderTraversal,
                         DefaultComparator{}, param_names);
}
