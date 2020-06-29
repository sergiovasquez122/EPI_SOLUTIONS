#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;

struct Iterator{
    vector<int>::const_iterator begin, end;

    bool operator>(const Iterator& rhs) const{
        return *begin > *rhs.begin;
    }
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    priority_queue<Iterator, vector<Iterator>, std::greater<>> minPQ;
    for(const auto& v : sorted_arrays){
        if(!v.empty()){
            minPQ.push({v.cbegin(), v.cend()});
        }
    }
    vector<int> result;
    while(!minPQ.empty()){
        auto curr = minPQ.top();
        minPQ.pop();
        result.push_back(*curr.begin);
        if(std::next(curr.begin) != curr.end){
            minPQ.push({std::next(curr.begin), curr.end});
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
