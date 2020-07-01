#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

struct Node{
    int height;
    bool balanced;
};

Node helper(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree == nullptr){
        return {-1, true};
    }

    auto left = helper(tree->left);
    if(!left.balanced){
        return {0, false};
    }

    auto right = helper(tree->right);
    if(!right.balanced){
        return {0, false};
    }

    int height = 1 + std::max(left.height, right.height);

    return {height, abs(left.height - right.height) <= 1};
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
    return helper(tree).balanced;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
