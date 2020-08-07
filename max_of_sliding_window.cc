#include <vector>
#include <deque>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;
using std::deque;

struct TrafficElement {
  bool operator<(const TrafficElement& that) const {
      return volume < that.volume || (volume == that.volume && time < that.time);
  }

  bool operator<=(const TrafficElement& that) const {
      return !(that < *this);
  }

  bool operator==(const TrafficElement& that) const {
    return time == that.time && volume == that.volume;
  }

  int time;
  double volume;
};

vector<TrafficElement> CalculateTrafficVolumes(const vector<TrafficElement>& A,
                                               int w) {
    vector<TrafficElement> result;
    deque<int> candidates;
    for(int window_end = 0;window_end < A.size();window_end++){
        while(!candidates.empty() && candidates.front() < window_end - w + 1){
            candidates.pop_front();
        }
        while(!candidates.empty() && A[candidates.back()] < A[window_end]){
            candidates.pop_back();
        }
        candidates.push_back(window_end);
        if(window_end >= w - 1){
            result.push_back(A[candidates.front()]);
        }
    }
    return result;
}

namespace test_framework {
template <>
struct SerializationTrait<TrafficElement>
    : UserSerTrait<TrafficElement, int, double> {};
}  // namespace test_framework

std::ostream& operator<<(std::ostream& out, const TrafficElement& te) {
  return out << '[' << te.time << ", " << te.volume << ']';
};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "w"};
  return GenericTestMain(args, "max_of_sliding_window.cc",
                         "max_of_sliding_window.tsv", &CalculateTrafficVolumes,
                         DefaultComparator{}, param_names);
}
