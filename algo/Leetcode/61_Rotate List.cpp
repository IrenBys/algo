// 61. Rotate List

/*
* Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr) return head;  

        ListNode* curr_last = head;
        size_t size = 1; // counting head 

        while (curr_last->next != nullptr) {
            curr_last = curr_last->next;
            size++;
        }

        int n = k % size;  // effective rotation steps
        if (n == 0) return head;  // no change

        curr_last->next = head;  // ring

        ListNode* new_last = head;
        // move to the node before the new head 
        for (int i = 0; i < size - n - 1; ++i) {
            new_last = new_last->next;
        }

        ListNode* new_head = new_last->next;  // new head after rotation
        new_last->next = nullptr;  // break ring

        return new_head;
    }
};
