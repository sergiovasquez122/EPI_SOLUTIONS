#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;
using std::sort;
struct Event {
  int start, finish;
};

struct endPoint{
    int point;
    bool isStart;
    bool operator <(const endPoint& rhs) const{
        if(point != rhs.point){
            return point < rhs.point;
        }
        return isStart && !rhs.isStart;
    }
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
    vector<endPoint> points;
    for(auto& e : A){
        points.push_back({e.start, true});
        points.push_back({e.finish, false});
    }
    sort(points.begin(), points.end());
    
    int current = 0, maxResult = 0;
    for(auto & e : points){
        if(e.isStart){
            current++;
            maxResult = std::max(maxResult, current);
        } else {
            current--;
        }
    }
    return maxResult;
}

namespace test_framework {
template <>
struct SerializationTrait<Event> : UserSerTrait<Event, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "calendar_rendering.cc",
                         "calendar_rendering.tsv", &FindMaxSimultaneousEvents,
                         DefaultComparator{}, param_names);
}
