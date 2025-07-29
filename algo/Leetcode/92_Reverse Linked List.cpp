// 92. Reverse Linked List II

/*
* Given the head of a singly linked list and two integers left and right where left <= right, 
* reverse the nodes of the list from position left to position right, and return the reversed list.
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
private:
    ListNode* recur_func(ListNode* node, ListNode* prev, ListNode* tail, int currPos, int right) {
        if (currPos > right) {
            tail->next = node;  // to the node after right pos
            return prev;
        }

        ListNode* nextNode = node->next;    // save next node before reversing
        node->next = prev;  // reverse the current node's pointer

        return recur_func(nextNode, node, tail, currPos + 1, right);
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode temp(0, head);
        ListNode* prev = &temp;

        // to the node before the left
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* tail = prev->next;  // node at  left pos  

        // node = tail - node at left pos
        // prev = nullptr - left pos is the head of a sublist
        // tail = tail - to connect a sublist after right pos
        // left, right - start and end pos of a sublist
        ListNode* newHead = recur_func(tail, nullptr, tail, left, right);

        prev->next = newHead; // ñonnect the node before left

        return temp.next;
    }
};
