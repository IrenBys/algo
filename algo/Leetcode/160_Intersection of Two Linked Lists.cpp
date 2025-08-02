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

        while (initialA) {
            listA_size++;
            initialA = initialA->next;
        }

        while (initialB) {
            listB_size++;
            initialB = initialB->next;
        }

        initialA = headA;
        initialB = headB;

        int skip = std::max(listA_size, listB_size) - std::min(listA_size, listB_size);
        if (listA_size > listB_size) {
            while (skip != 0) {
                initialA = initialA->next;
                skip--;
            }
        }
        else {
            while (skip != 0) {
                initialB = initialB->next;
                skip--;
            }
        }

        while (initialA && initialB) {
            if (initialA == initialB) {
                return initialA;
            }
            else {
                initialA = initialA->next;
                initialB = initialB->next;
            }
        }
        return nullptr;
    }
};
