#include <vector>

#include "test_framework/generic_test.h"
#include <queue>
using std::vector;
using std::priority_queue;

struct Iterator{
    bool operator>(const Iterator& rhs) const {
        return *left > *rhs.left;
    }
    vector<int>::const_iterator left, right;
};

vector<int> merge(const vector<vector<int>>& A){
    priority_queue<Iterator, vector<Iterator>, std::greater<>> pq;
    for(const auto& v : A)
        pq.push(Iterator{v.cbegin(), v.cend()});

    vector<int> result;
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        result.push_back(*current.left);
        if(std::next(current.left) != current.right){
            pq.push(Iterator{std::next(current.left), current.right});
        }
    }
    return result;
}

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
    bool increasing = true;
    vector<vector<int>> partitions;
    int starting_idx = 0;
    for(int i = 1;i <= A.size();++i){
        if((i == A.size()) || (increasing && A[i - 1] > A[i])
        || (!increasing && A[i-1] < A[i])){
            if(increasing){
                partitions.emplace_back(A.cbegin() + starting_idx, A.cbegin() + i);
            } else {
                partitions.emplace_back(A.crbegin() + A.size() - i, A.crbegin() + A.size() - starting_idx);
            }
            starting_idx = i;
            increasing = !increasing;
        }
    }
    return merge(partitions);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "sort_increasing_decreasing_array.cc",
                         "sort_increasing_decreasing_array.tsv",
                         &SortKIncreasingDecreasingArray, DefaultComparator{},
                         param_names);
}
