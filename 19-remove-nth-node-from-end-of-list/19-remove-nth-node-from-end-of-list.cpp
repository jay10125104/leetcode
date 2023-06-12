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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*mid = new ListNode(-1);
        mid->next=head;
        ListNode*slow=mid;
        ListNode*fast=mid;
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        // cout<<slow->val<<endl;
        slow->next=slow->next->next;
        return mid->next;
    }
};