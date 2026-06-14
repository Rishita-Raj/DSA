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
    int pairSum(ListNode* head) {

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev is head of reversed second half
        ListNode* first = head;
        ListNode* second = prev;

        int maxTwinSum = 0;

        // Step 3: Compute twin sums
        while (second) {
            maxTwinSum = max(maxTwinSum,
                             first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return maxTwinSum;
    }
};