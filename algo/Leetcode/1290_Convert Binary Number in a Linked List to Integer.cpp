// 1290. Convert Binary Number in a Linked List to Integer

/*
* Given head which is a reference node to a singly-linked list. 
* The value of each node in the linked list is either 0 or 1. 
* The linked list holds the binary representation of a number.
* Return the decimal value of the number in the linked list.
* The most significant bit is at the head of the linked list
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
    int getDecimalValue(ListNode* head) {
        ListNode* current = head;
        int len = 0;
        int res = 0;
        int power = 0;

        // length of the list to know the highest power
        while (current != nullptr) {
            len++;
            current = current->next;
        }

        current = head;
        power = len - 1; // start with the highest power

        while (current != nullptr) {
            if (current->val == 1) {
                // if current bit is 1, add 2^power to the res
                int value = 1;
                for (int i = 0; i < power; ++i) {
                    value *= 2;
                }
                res += value;
            }
            power--;
            current = current->next;
        }

        return res;

    }
};
