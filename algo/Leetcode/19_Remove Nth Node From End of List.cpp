// 19. Remove Nth Node From End of List

/*
* Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;

        // length of list
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        // search deleted node
        int del = len - n;
        curr = head;
        ListNode* prev = nullptr; // save prev deleted node

        while (del != 0) {
            del--;
            prev = curr;
            curr = curr->next;
        }

        // if deleted node is a head
        if (prev == nullptr) {
            head = head->next;
            delete curr;
            return head;
        }

        prev->next = curr->next;
        delete curr;
        return head;
    }
};
