#include <memory>
#include <stack>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::stack;

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
    auto root = tree.get();
    BinaryTreeNode<int>* parent = nullptr;
    stack<BinaryTreeNode<int>*> elements;
    while(root || !elements.empty()){
        while(root != nullptr){
            elements.push(root);
            root = root->left.get();
        }
        root = elements.top();
        elements.pop();
        if(parent && parent->data > root->data) return false;
        parent = root;
        root = root->right.get();
    }
    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
