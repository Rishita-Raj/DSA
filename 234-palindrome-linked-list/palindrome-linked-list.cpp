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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* front = temp->next;

            temp->next = prev;
            prev = temp;

            temp = front;
        }
        return prev;
}

    bool isPalindrome(ListNode* head) {
         // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer one step at a time
        fast = fast->next->next; // Move fast pointer two steps at a time
    }

    // Reverse the second half of the linked list starting from the middle
    ListNode* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    ListNode* first = head;

    // Pointer to the reversed second half
    ListNode* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->val != second->val) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
    }
};