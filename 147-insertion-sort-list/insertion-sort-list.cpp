/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Dummy node for sorted list
        ListNode* dummy = new ListNode(0);

        while (head != nullptr) {
            ListNode* curr = head;
            head = head->next;

            // Find correct position to insert
            ListNode* prev = dummy;
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert current node
            curr->next = prev->next;
            prev->next = curr;
        }

        return dummy->next;
    }
};
