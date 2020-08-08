#include <memory>
#include <stack>
#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;
using std::stack;

shared_ptr<BstNode<int>> BSTToDoublyLinkedList(
        const shared_ptr<BstNode<int>>& tree) {
  stack<shared_ptr<BstNode<int>>> on_stack;
  auto iter = tree;
  auto pre = iter;
  pre = nullptr;
  auto result = pre;
  while(iter || !on_stack.empty()){
    while(iter){
      on_stack.push(iter);
      iter = iter->left;
    }
    iter = on_stack.top();
    on_stack.pop();
    if(!pre) result = iter;
    if(pre){
      pre->right = iter;
      iter->left = pre;
    }
    pre = iter;
    iter = iter->right;
  }
  return result;
}

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
    auto lhs = BSTToDoublyLinkedList(A); // O(n)
    auto rhs = BSTToDoublyLinkedList(B); // O(n)
    // merge items
    // count length
    return
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "bst_merge.cc", "bst_merge.tsv", &MergeTwoBSTs,
                         DefaultComparator{}, param_names);
}
