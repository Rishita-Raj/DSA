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
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* current = slow;
        ListNode* temp;
        while(current != NULL)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        
        ListNode* first = head;
        ListNode* second = prev;
        while(second->next != NULL)
        {
            temp = first->next;
            first->next = second;
            first = temp;
            
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};