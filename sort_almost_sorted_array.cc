#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;

vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {
  priority_queue<int, vector<int>, std::greater<>> pq;
  vector<int> result;
  while(sequence_begin != sequence_end){
    pq.push(*sequence_begin++);
    if(pq.size() > k){
      result.push_back(pq.top());
      pq.pop();
    }
  }
  while(!pq.empty()){
    result.push_back(pq.top());
    pq.pop();
  }
  return result;
}
vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
  return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence", "k"};
  return GenericTestMain(
      args, "sort_almost_sorted_array.cc", "sort_almost_sorted_array.tsv",
      &SortApproximatelySortedDataWrapper, DefaultComparator{}, param_names);
}
