#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool bellmanFord(const vector<vector<double>>& graph, int s){
    vector<double> dist_to_source(graph.size(), std::numeric_limits<double>::max());
    dist_to_source[s] = 0;
    for(int times = 1;times < graph.size();++times){
        for(int i = 0;i < graph.size();i++){
            for(int j = 0;j < graph[i].size();j++){
                if (dist_to_source[i] != std::numeric_limits<double>::max() && dist_to_source[j] > dist_to_source[i] + graph[i][j]){
                    dist_to_source[j] = dist_to_source[i] + graph[i][j];
                }
            }
        }
    }
    
    for(int i = 0;i < graph.size();i++){
        for(int j = 0;j < graph[i].size();j++){
                 if (dist_to_source[i] != std::numeric_limits<double>::max() && dist_to_source[j] > dist_to_source[i] + graph[i][j]){
                     return true;
                }
        }
    }
    return false;
}

bool IsArbitrageExist(vector<vector<double>> graph) {
    for(int i = 0;i < graph.size();i++){
      for(int j = 0;j < graph[0].size();j++){
          graph[i][j] = -log10(graph[i][j]);
      }
    }
    return bellmanFord(graph, 0);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"graph"};
  return GenericTestMain(args, "arbitrage.cc", "arbitrage.tsv",
                         &IsArbitrageExist, DefaultComparator{}, param_names);
}
