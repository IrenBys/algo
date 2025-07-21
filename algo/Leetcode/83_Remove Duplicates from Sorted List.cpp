// 83. Remove Duplicates from Sorted List
/*
* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
* Return the linked list sorted as well.
*/

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* result = head;

    while (head != nullptr && head->next != nullptr) {
        if (head->val == head->next->val) {
            head->next = head->next->next;
        }
        else {
            head = head->next;
        }
    }
    return result;
}