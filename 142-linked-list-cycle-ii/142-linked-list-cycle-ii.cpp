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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        if(slow->next==NULL){
            return NULL;
        }
        do{
            if(slow->next==NULL){
                return NULL;
            }
            slow=slow->next;
            if(fast==NULL){
                return NULL;
            }
            if(fast->next==NULL){
                return NULL;
            }
            if(fast->next->next==NULL){
                return NULL;
            }
            fast = fast->next->next;
            
        }while(fast!=slow);
        fast = head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};