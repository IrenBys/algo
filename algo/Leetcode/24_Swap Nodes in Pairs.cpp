// 24. Swap Nodes in Pairs

/*
* Given a linked list, swap every two adjacent nodes and return its head. 
* You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode temp(0, head);
        ListNode* prev = &temp;

        ListNode* first;
        ListNode* second;

        while ((prev->next != nullptr) && (prev->next->next != nullptr)) {
            first = prev->next;
            second = first->next;

            first->next = second->next;
            second->next = first;

            prev->next = second;
            prev = first;
        }

        return temp.next;
    }
};
