#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L,
                                                   int k) {
    if(L == nullptr){
        return nullptr;
    }
    int length = 0;
    for(auto iter = L;iter != nullptr;iter = iter->next){
        length++;
    }

    if(k > length){
        k %= length;
    }

    if(k == 0){
        return L;
    }

    int walk = length - k;
    auto iter = L;
    auto pre = L;
    while(walk--){
        pre = iter;
        iter = iter->next;
    }
    pre->next = nullptr;

    auto tail = iter;
    while(tail->next){
        tail = tail->next;
    }
    tail->next = L;
    return iter;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(
      args, "list_cyclic_right_shift.cc", "list_cyclic_right_shift.tsv",
      &CyclicallyRightShiftList, DefaultComparator{}, param_names);
}
