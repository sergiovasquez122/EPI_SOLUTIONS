#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> reverse(shared_ptr<ListNode<int>>& L){
    auto iter = L;
    auto reversed = iter;
    reversed = nullptr;
    while(iter){
       auto temp = iter->next;
       iter->next = reversed;
       reversed = iter;
       iter = temp;
    }
    return reversed;
}

shared_ptr<ListNode<int>> ZippingLinkedList(
    const shared_ptr<ListNode<int>>& L) {
    if(!L || !L->next){
        return L;
    }
    auto slow_ptr = L, fast_ptr = L;

    while(fast_ptr->next && fast_ptr->next->next){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    auto rhs = slow_ptr->next;
    slow_ptr->next = nullptr;
    auto L2 = reverse(rhs);
    auto L1 = L, tail = L2;
    while(L1 && L2){
        auto L1_temp = L1->next;
        auto L2_temp = L2->next;
        L1->next = L2;
        L2->next = L1_temp;
        L1 = L1_temp;
        L2 = L2_temp;
        if(L2){
           tail = L1;
        }
    }
    if(L2){
        tail->next = L2;
    }
    return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "zip_list.cc", "zip_list.tsv",
                         &ZippingLinkedList, DefaultComparator{}, param_names);
}
