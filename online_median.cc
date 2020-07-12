#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;

vector<double> OnlineMedian(vector<int>::const_iterator sequence_begin,
                            const vector<int>::const_iterator& sequence_end) {
    vector<double> result;
    priority_queue<int, vector<int>, std::less<>> max_pq;
    priority_queue<int, vector<int>, std::greater<>> min_pq;
    while(sequence_begin != sequence_end){
        max_pq.push(*sequence_begin++);
        min_pq.push(max_pq.top());
        max_pq.pop();
        if(max_pq.size() < min_pq.size()){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }

        double value = (max_pq.size() == min_pq.size()) ? 0.5 * (min_pq.top() + max_pq.top()) : max_pq.top();
        result.push_back(value);

    }
    return result;
}

vector<double> OnlineMedianWrapper(const vector<int>& sequence) {
  return OnlineMedian(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "online_median.cc", "online_median.tsv",
                         &OnlineMedianWrapper, DefaultComparator{},
                         param_names);
}
