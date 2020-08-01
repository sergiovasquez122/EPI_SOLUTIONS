#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;
using std::unordered_map;
using std::map;
using std::unordered_set;

class ClientsCreditsInfo {
 public:
  void Insert(const string& client_id, int c) {

  }
  bool Remove(const string& client_id) {
      auto it = client_to_credits.find(client_id);
      if(it == client_to_credits.end()){
          return false;
      }
      int c = it->second;
      credits_to_clients[c].erase(client_id);
      client_to_credits.erase(client_id);
      return true;
  }
  int Lookup(const string& client_id) const {
      auto it = client_to_credits.find(client_id);
      if(it == client_to_credits.cend()){
        return -1;
      }
      return it->second + global_credits;
  }
  void AddAll(int C) {
      global_credits += C;
  }
  string Max() const {
      auto it = credits_to_clients.crbegin();
      if(it == credits_to_clients.crend()){
        return "";
      }
      return *it->second.begin();
  }
private:
    int global_credits = 0;
    unordered_map<string, int> client_to_credits;
    map<int, unordered_set<string>> credits_to_clients;
};
struct Operation {
  std::string op;
  std::string s_arg;
  int i_arg;
};

std::ostream& operator<<(std::ostream& out, const Operation& op) {
  return out << FmtStr("{}({}, {})", op.op, op.s_arg, op.i_arg);
}

namespace test_framework {
template <>
struct SerializationTrait<Operation>
    : UserSerTrait<Operation, std::string, std::string, int> {};
}  // namespace test_framework
void ClientsCreditsInfoTester(const std::vector<Operation>& ops) {
  ClientsCreditsInfo cr;
  int op_idx = 0;
  for (auto& op : ops) {
    if (op.op == "ClientsCreditsInfo") {
      continue;
    } else if (op.op == "remove") {
      bool result = cr.Remove(op.s_arg);
      if (result != op.i_arg) {
        throw TestFailure()
            .WithProperty(PropertyName::STATE, cr)
            .WithProperty(PropertyName::COMMAND, op)
            .WithMismatchInfo(op_idx, op.i_arg, result);
      }
    } else if (op.op == "max") {
      auto result = cr.Max();
      if (result != op.s_arg) {
        throw TestFailure()
            .WithProperty(PropertyName::STATE, cr)
            .WithProperty(PropertyName::COMMAND, op)
            .WithMismatchInfo(op_idx, op.i_arg, result);
      }
    } else if (op.op == "insert") {
      cr.Insert(op.s_arg, op.i_arg);
    } else if (op.op == "add_all") {
      cr.AddAll(op.i_arg);
    } else if (op.op == "lookup") {
      auto result = cr.Lookup(op.s_arg);
      if (result != op.i_arg) {
        throw TestFailure()
            .WithProperty(PropertyName::STATE, cr)
            .WithProperty(PropertyName::COMMAND, op)
            .WithMismatchInfo(op_idx, op.i_arg, result);
        ;
      }
    }
    op_idx++;
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "adding_credits.cc", "adding_credits.tsv",
                         &ClientsCreditsInfoTester, DefaultComparator{},
                         param_names);
}
