/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        dfs(head);
        return head;
    }

    Node* dfs(Node* head) {
        Node* curr = head;
        Node* last = head;

        while (curr) {
            Node* next = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                curr->child = NULL; 
                last = childTail;
            } else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }
};