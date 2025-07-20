//21. Merge Two Sorted Lists

/*
* You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/



// Definition for singly - linked list.
struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
   
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode result(0, nullptr); // пустой список
    ListNode* head = &result;   // указываем на голову

    while (list1 && list2) {
        if (list1->val < list2->val) {
            head->next = list1;
            list1 = list1->next;
        }
        else {
            head->next = list2;
            list2 = list2->next;
        }

        head = head->next; // перемещаем голову нового result
    }

    if (list1 == nullptr)
    {
        head->next = list2; // остаток или весь list2
    }

    if (list2 == nullptr) {
        head->next = list1; // отстаток или list1
    }
    return result.next; // чтобы не возвращать пустую голову, которую задали в начале, а возвращаем начиная с первого элемента list1 или list2
}