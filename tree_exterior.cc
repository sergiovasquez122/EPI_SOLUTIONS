#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;
using std::unique_ptr;

bool isLeaf(const unique_ptr<BinaryTreeNode<int>>& root){
    return !root->left && !root->right;
}

void collect_right(const unique_ptr<BinaryTreeNode<int>>& root, vector<const unique_ptr<BinaryTreeNode<int>>*>& result,
                  bool is_boundary){
    if(!root){
        return;
    }

    collect_right(root->left, result, root->right == nullptr && is_boundary);
    collect_right(root->right, result, is_boundary);

    if(isLeaf(root) || is_boundary){
        result.push_back(&root);
    }

}

void collect_left(const unique_ptr<BinaryTreeNode<int>>& root, vector<const unique_ptr<BinaryTreeNode<int>>*>& result,
        bool is_boundary){
        if(!root){
            return;
        }

        if(isLeaf(root) || is_boundary){
            result.push_back(&root);
        }

        collect_left(root->left, result, is_boundary);
        collect_left(root->right, result, root->left == nullptr && is_boundary);
}

vector<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
    vector<const unique_ptr<BinaryTreeNode<int>>*> result;
    if(tree != nullptr){
        result.push_back(&tree);
        collect_left(tree->left, result,true);
        collect_right(tree->right, result, true);
    }
    return result;
}

vector<int> CreateOutputVector(
    const vector<const unique_ptr<BinaryTreeNode<int>>*>& L) {
  if (std::find(std::begin(L), std::end(L), nullptr) != std::end(L)) {
    throw TestFailure("Resulting list contains nullptr");
  }
  std::vector<int> output;
  for (const auto* l : L) {
    output.push_back((*l)->data);
  }
  return output;
}

vector<int> ExteriorBinaryTreeWrapper(
    TimedExecutor& executor, const unique_ptr<BinaryTreeNode<int>>& tree) {
  auto result = executor.Run([&] { return ExteriorBinaryTree(tree); });

  return CreateOutputVector(result);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree"};
  return GenericTestMain(args, "tree_exterior.cc", "tree_exterior.tsv",
                         &ExteriorBinaryTreeWrapper, DefaultComparator{},
                         param_names);
}
