#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> merge(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2){
    ListNode<int> dummy;
    auto tail = &dummy;
    while(l1 && l2){
        if(l1->data < l2->data){
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next.get();
        } else {
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next.get();
        }
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
    if(L == nullptr || L->next == nullptr){
        return L;
    }

    shared_ptr<ListNode<int>> slow = L, fast = L, pre = nullptr;

    while(fast && fast->next){
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    pre->next = nullptr;
    auto lhs = StableSortList(L);
    auto rhs = StableSortList(slow);
    return merge(lhs, rhs);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "sort_list.cc", "sort_list.tsv", &StableSortList,
                         DefaultComparator{}, param_names);
}
