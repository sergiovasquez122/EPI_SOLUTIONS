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

int countLength(shared_ptr<BstNode<int>> A){
    int length = 0;
    for(auto iter = A;iter != nullptr;iter = iter->right){
        length++;
    }
    return length;
}


shared_ptr<BstNode<int>> helper(shared_ptr<BstNode<int>>* l_ref, int start,int end){
    if(end < start) return nullptr;
    int mid = start + (end - start) / 2;
    auto left = helper(l_ref, start, mid - 1);
    auto curr = *l_ref;
    curr->left = left;
    *l_ref = (*l_ref)->right;
    curr->right = helper(l_ref, mid + 1, end);
    return curr;
}

shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyList(
        shared_ptr<BstNode<int>> l, int length) {
if(l == nullptr) return nullptr;
return helper(&l, 0, length - 1);
}

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
    auto lhs = BSTToDoublyLinkedList(A); // O(n)
    auto rhs = BSTToDoublyLinkedList(B); // O(n)
    int lhs_length = countLength(A);
    int rhs_length = countLength(B);
    return BuildBSTFromSortedDoublyList(lhs, lhs_length + rhs_length);

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "bst_merge.cc", "bst_merge.tsv", &MergeTwoBSTs,
                         DefaultComparator{}, param_names);
}
