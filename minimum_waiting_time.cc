#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int MinimumTotalWaitingTime(vector<int> service_times) {
  if(service_times.empty()){
    return 0;
  }
  std::sort(service_times.begin(), service_times.end());
  int total = 0;
  int running_sum = 0;
  for(int i = 0;i < service_times.size() - 1;++i){
    running_sum += service_times[i];
    total += running_sum;
  }
  return total;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"service_times"};
  return GenericTestMain(args, "minimum_waiting_time.cc",
                         "minimum_waiting_time.tsv", &MinimumTotalWaitingTime,
                         DefaultComparator{}, param_names);
}
