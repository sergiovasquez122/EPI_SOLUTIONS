#include <unordered_map>
#include <list>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
using std::unordered_map;
using std::list;
using std::pair;

class LruCache {
 public:
  LruCache(size_t capacity){
      size = capacity;
  }
  int Lookup(int isbn) {
    auto it = table.find(isbn);
    if(it == table.end()){
        return -1;
    }
    cache.erase(it->second.first);
    cache.emplace_front(isbn);
    table[isbn] = {cache.begin(), it->second.second};
    return it->second.second;
  }
  void Insert(int isbn, int price) {
      auto it = table.find(isbn);
      if(it != table.end()){
          cache.erase(it->second.first);
          cache.emplace_front(isbn);
          table[isbn] = {cache.begin(), price};
      } else {
          if(size == cache.size()){
              int val = cache.back();
              cache.pop_back();
              table.erase(val);
          }
          cache.emplace_front(isbn);
          table[isbn] = {cache.begin(), price};
      }
  }

  bool Erase(int isbn) {
      auto it = table.find(isbn);
      if(it == table.end()){
        return false;
      }
      cache.erase(it->second.first);
      table.erase(it);
      return true;
  }
private:
    unordered_map<int, pair<list<int>::iterator, int>> table;
    list<int> cache;
    size_t size;
};

struct Op {
  std::string code;
  int arg1;
  int arg2;
};

namespace test_framework {
template <>
struct SerializationTrait<Op> : UserSerTrait<Op, std::string, int, int> {};
}  // namespace test_framework

void LruCacheTester(const std::vector<Op>& commands) {
  if (commands.empty() || commands[0].code != "LruCache") {
    throw std::runtime_error("Expected LruCache as first command");
  }
  LruCache cache(commands[0].arg1);

  for (int i = 1; i < commands.size(); i++) {
    auto& cmd = commands[i];
    if (cmd.code == "lookup") {
      int result = cache.Lookup(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailure("Lookup: expected " + std::to_string(cmd.arg2) +
                          ", got " + std::to_string(result));
      }
    } else if (cmd.code == "insert") {
      cache.Insert(cmd.arg1, cmd.arg2);
    } else if (cmd.code == "erase") {
      bool result = cache.Erase(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailure("Erase: expected " + std::to_string(cmd.arg2) +
                          ", got " + std::to_string(result));
      }
    } else {
      throw std::runtime_error("Unexpected command " + cmd.code);
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"commands"};
  return GenericTestMain(args, "lru_cache.cc", "lru_cache.tsv", &LruCacheTester,
                         DefaultComparator{}, param_names);
}
