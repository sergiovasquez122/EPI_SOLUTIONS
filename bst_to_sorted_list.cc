#include <memory>
#include <vector>
#include <stack>
#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"


using namespace std;

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

std::vector<int> BSTToDoublyLinkedListWrapper(
    TimedExecutor& executor, const std::shared_ptr<BstNode<int>>& tree) {
  auto list = executor.Run([&] { return BSTToDoublyLinkedList(tree); });

  if (list && list->left) {
    throw TestFailure(
        "Function must return the head of the list. Left link must be null");
  }
  std::vector<int> v;
  while (list) {
    v.push_back(list->data);
    if (list->right && list->right->left != list) {
      throw TestFailure("List is ill-formed");
    }
    list = list->right;
  }
  return v;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree"};
  return GenericTestMain(
      args, "bst_to_sorted_list.cc", "bst_to_sorted_list.tsv",
      &BSTToDoublyLinkedListWrapper, DefaultComparator{}, param_names);
}
