#include <algorithm>

// 160. Intersection of Two Linked Lists

/*
* Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
* If the two linked lists have no intersection at all, return null.
*/

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        size_t listA_size = 0;
        size_t listB_size = 0;

        ListNode* initialA = headA;
        ListNode* initialB = headB;

        while (headA)
        {
            listA_size++;
            headA = headA->next;
        }

        while (headB)
        {
            listB_size++;
            headB = headB->next;
        }

        headA = initialA;
        headB = initialB;

        int skip = std::max(listA_size, listB_size) - std::min(listA_size, listB_size);
        if (listA_size > listB_size) {
            while (skip != 0) {
                headA = headA->next;
                skip--;
            }
        }
        else {
            while (skip != 0) {
                headB = headB->next;
                skip--;
            }
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};