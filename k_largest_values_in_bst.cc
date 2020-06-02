#include <memory>
#include <vector>
#include <stack>
#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;
using std::stack;

vector<int> FindKLargestInBST(const unique_ptr<BstNode<int>>& tree, int k) {
  vector<int> result;
  stack<BstNode<int>*> elements;
  auto root = tree.get();
  elements.push(root);
  while((root || !elements.empty()) && result.size() < k){
    while(root != nullptr){
      elements.push(root);
      root = root->right.get();
    }
    root = elements.top();
    elements.pop();
    if(result.size() < k){
        result.emplace_back(root->data);
    }
    root = root->left.get();
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "k"};
  return GenericTestMain(args, "k_largest_values_in_bst.cc",
                         "k_largest_values_in_bst.tsv", &FindKLargestInBST,
                         UnorderedComparator{}, param_names);
}
