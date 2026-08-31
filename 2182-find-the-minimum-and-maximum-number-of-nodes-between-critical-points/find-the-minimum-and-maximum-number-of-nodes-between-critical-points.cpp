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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical;
        int i=1;
        ListNode* temp=head->next;
        ListNode* prev=head;

        int first =-1, last=-1;
        int mini=INT_MAX;
        while(temp->next){
            if(temp->val<prev->val and temp->val<temp->next->val || temp->val>prev->val and temp->val>temp->next->val){
                if(first==-1){
                    first=i;
                }else{
                    mini=min(mini,i-last);
                }
                last=i;
            }
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(first==-1 or first==last) return {-1,-1};
        return {mini,last-first};
    }
};