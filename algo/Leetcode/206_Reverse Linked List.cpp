//206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
private:
    ListNode* recur_func(ListNode* node, ListNode* prev) {
        // to the end of List
        if (node == nullptr) {
            return prev;
        }
        ListNode* nextNode = node->next; // save next node before changing the current node's pointer
        node->next = prev;
        return recur_func(nextNode, node); // reverse the current node's pointer to point to the previous node
    }


public:
    ListNode* reverseList(ListNode* head) {
        return recur_func(head, nullptr);

    }
};
