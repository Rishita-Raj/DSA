/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;

        ListNode* temp = node->next;
        node->next = node->next->next;

        delete temp;
    }
};

// ListNode* deleteHead(ListNode* head) {

//     // If the list is empty
//     if(head == NULL)
//         return NULL;

//     // Store the current head node
//     ListNode* temp = head;

//     // Move head to the next node
//     head = head->next;

//     // Delete the old head
//     delete temp;

//     // Return the new head
//     return head;
// }