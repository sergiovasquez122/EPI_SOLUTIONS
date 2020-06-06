#include <memory>

#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
BstNode<int>* SearchBST(const unique_ptr<BstNode<int>>& tree, int key) {
    auto iter = tree.get();
    while(iter){
      if(iter->data < key){
        iter = iter->right.get();
      } else if(iter->data > key){
          iter = iter->left.get();
      } else {
          return iter;
      }
    }
    return iter;
}

int SearchBSTWrapper(const unique_ptr<BstNode<int>>& tree, int key) {
  auto result = SearchBST(tree, key);
  return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "key"};
  return GenericTestMain(args, "search_in_bst.cc", "search_in_bst.tsv",
                         &SearchBSTWrapper, DefaultComparator{}, param_names);
}
