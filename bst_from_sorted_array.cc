#include <memory>
#include <vector>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::unique_ptr;
using std::make_unique;
using std::vector;

unique_ptr<BstNode<int>> helper(const vector<int>& A, int lower_bound, int upper_bound){
    if(upper_bound < lower_bound) return nullptr;
    int mid = lower_bound + (upper_bound - lower_bound) / 2;
    return make_unique<BstNode<int>>(BstNode<int>{A[mid], helper(A, lower_bound, mid - 1),
                                                  helper(A, mid + 1, upper_bound)});
}

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedArray(
        const vector<int>& A) {
    return helper(A, 0, A.size() - 1);
}

int BuildMinHeightBSTFromSortedArrayWrapper(TimedExecutor& executor,
                                            const vector<int>& A) {
  auto result =
      executor.Run([&] { return BuildMinHeightBSTFromSortedArray(A); });

  if (test_framework::GenerateInorder(result) != A) {
    throw TestFailure("Result binary tree mismatches input array");
  }
  return test_framework::BinaryTreeHeight(result);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, "bst_from_sorted_array.cc",
                         "bst_from_sorted_array.tsv",
                         &BuildMinHeightBSTFromSortedArrayWrapper,
                         DefaultComparator{}, param_names);
}
