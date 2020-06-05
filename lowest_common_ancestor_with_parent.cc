#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
    int height_1 = 0, height_2 = 0;
    auto iter1 = node0.get();
    while(iter1){
      iter1 = iter1->parent;
      height_1++;
    }

    auto iter2 = node1.get();
    while(iter2){
        iter2 = iter2->parent;
        height_2++;
    }

    int diff = abs(height_2 - height_1);

    iter1 = height_1 < height_2 ? node1.get() : node0.get();
    while(diff--){
        iter1 = iter1->parent;
    }

    iter2 = height_1 < height_2 ? node0.get() : node1.get();
    while(iter1 && iter2){
        if(iter1 == iter2){
            return iter1;
        }
        iter1 = iter1->parent;
        iter2 = iter2->parent;
    }

    return iter1;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
