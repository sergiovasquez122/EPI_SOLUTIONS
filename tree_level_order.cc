#include <memory>
#include <vector>
#include <queue>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;
using std::queue;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
    vector<vector<int>> result;
    queue<BinaryTreeNode<int>*> curr_depth_nodes({tree.get()});
    while(!curr_depth_nodes.empty()){
        vector<int> this_level;
        queue<BinaryTreeNode<int>*> next_level_nodes;
        while(!curr_depth_nodes.empty()){
            auto curr = curr_depth_nodes.front();
            curr_depth_nodes.pop();

            if(curr){
                this_level.push_back(curr->data);

                next_level_nodes.push(curr->left.get());
                next_level_nodes.push(curr->right.get());
            }
        }
        if(!this_level.empty()){
            result.push_back(this_level);
        }
        std::swap(curr_depth_nodes, next_level_nodes);
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
