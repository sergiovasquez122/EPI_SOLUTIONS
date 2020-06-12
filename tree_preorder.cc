#include <vector>
#include <stack>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::vector;
using std::stack;
vector<int> PreorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    stack<const BinaryTreeNode<int>*> on_stack;
    vector<int> result;
    on_stack.push(tree.get());
    while(!on_stack.empty()){
        auto curr = on_stack.top();
        on_stack.pop();
        if(curr){
            result.push_back(curr->data);
            on_stack.push(curr->right.get());
            on_stack.push(curr->left.get());
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_preorder.cc", "tree_preorder.tsv",
                         &PreorderTraversal, DefaultComparator{}, param_names);
}
