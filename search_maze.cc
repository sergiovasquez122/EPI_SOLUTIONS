#include <istream>
#include <string>
#include <vector>
#include <array>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;
using std::array;
enum class Color { kWhite, kBlack };
struct Coordinate {
  bool operator==(const Coordinate& that) const {
    return x == that.x && y == that.y;
  }

  int x, y;
};


bool valid_placement(vector<vector<Color>>& maze, const Coordinate& s){
    return s.x >= 0 && maze.size() > s.x && s.y >= 0 && s.y < maze[0].size() && maze[s.x][s.y] == Color ::kWhite;
}

bool dfs(vector<vector<Color>>& maze, vector<Coordinate>& result, const Coordinate& u, const Coordinate& e){
    maze[u.x][u.y] = Color::kBlack;
    result.push_back(u);
    if(u == e){
        return true;
    }

    const vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto& move : moves){
        Coordinate newCoordinate{u.x + move[0], u.y + move[1]};
        if(valid_placement(maze, newCoordinate) && dfs(maze, result, newCoordinate, e)){
            return true;
        }
    }

    result.pop_back();
    return false;
}

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s,
                              const Coordinate& e) {
    vector<Coordinate> result;
    if(dfs(maze, result, s, e)){
        return result;
    }
    return {};
}

namespace test_framework {
template <>
struct SerializationTrait<Color> : SerializationTrait<int> {
  using serialization_type = Color;

  static serialization_type Parse(const json& json_object) {
    return static_cast<serialization_type>(
        SerializationTrait<int>::Parse(json_object));
  }
};
}  // namespace test_framework

namespace test_framework {
template <>
struct SerializationTrait<Coordinate> : UserSerTrait<Coordinate, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {};
  }

  static std::vector<int> GetMetrics(const Coordinate& x) { return {}; }
};
}  // namespace test_framework

bool PathElementIsFeasible(const vector<vector<Color>>& maze,
                           const Coordinate& prev, const Coordinate& cur) {
  if (!(0 <= cur.x && cur.x < maze.size() && 0 <= cur.y &&
        cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == Color::kWhite)) {
    return false;
  }
  return cur == Coordinate{prev.x + 1, prev.y} ||
         cur == Coordinate{prev.x - 1, prev.y} ||
         cur == Coordinate{prev.x, prev.y + 1} ||
         cur == Coordinate{prev.x, prev.y - 1};
}

bool SearchMazeWrapper(TimedExecutor& executor,
                       const vector<vector<Color>>& maze, const Coordinate& s,
                       const Coordinate& e) {
  vector<vector<Color>> copy = maze;

  auto path = executor.Run([&] { return SearchMaze(copy, s, e); });

  if (path.empty()) {
    return s == e;
  }

  if (!(path.front() == s) || !(path.back() == e)) {
    throw TestFailure("Path doesn't lay between start and end points");
  }

  for (size_t i = 1; i < path.size(); i++) {
    if (!PathElementIsFeasible(maze, path[i - 1], path[i])) {
      throw TestFailure("Path contains invalid segments");
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "maze", "s", "e"};
  return GenericTestMain(args, "search_maze.cc", "search_maze.tsv",
                         &SearchMazeWrapper, DefaultComparator{}, param_names);
}
