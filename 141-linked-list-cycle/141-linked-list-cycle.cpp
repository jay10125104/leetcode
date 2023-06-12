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
    bool hasCycle(ListNode *head) {
       
        if(!head){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
         ListNode*fast = head->next;
        ListNode*slow = head;
        while(fast && fast->next && fast!=slow){
            cout<<fast->val<<" "<<slow->val<<endl;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow==fast;
    }
};