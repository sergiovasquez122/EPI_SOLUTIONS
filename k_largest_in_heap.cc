#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;

struct heapEntry{
    int i, value;
    bool operator<(const heapEntry& rhs) const {
        return value < rhs.value;
    }
};

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
    if(A.empty()){
        return {};
    }
    priority_queue<heapEntry> max_pq;
    vector<int> result;
    max_pq.push({0, A[0]});
    while(result.size() != k){
        auto curr = max_pq.top();
        max_pq.pop();
        result.push_back(curr.value);
        int left_child_idx = 2 * curr.i + 1;
        if(left_child_idx < A.size())
            max_pq.push({left_child_idx, A[left_child_idx]});

        int right_child_idx = 2 * curr.i + 2;
        if(right_child_idx < A.size())
            max_pq.push({right_child_idx, A[right_child_idx]});
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "k_largest_in_heap.cc", "k_largest_in_heap.tsv",
                         &KLargestInBinaryHeap, UnorderedComparator{},
                         param_names);
}
