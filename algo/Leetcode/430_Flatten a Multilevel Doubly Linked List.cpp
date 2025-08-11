// 430. Flatten a Multilevel Doubly Linked List


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {

        if (head == nullptr) return head;

        Node* curr = head;
        Node* after = nullptr;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* child_head = curr->child;
                Node* child_head_new = curr->child;
                Node* new_after = nullptr;


                after = curr->next;
                curr->child->prev = curr;
                curr->next = curr->child;
                curr->child = nullptr;

                curr = curr->next;


                Node* tail = child_head;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                tail->next = after;
                if (after != nullptr) after->prev = tail;

            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};
