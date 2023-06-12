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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*ans = new ListNode(-1);
        ListNode*temp = ans;
        ListNode*ptr = head;
        while(ptr!=NULL){
            // cout<<ptr->val<<endl;
            temp->next=ptr;
            ptr=ptr->next;
            int count=0;
            while(ptr && (ptr->val==temp->next->val)){
                count++;
                // cout<<ptr->val<<" "<<temp->next->val<<endl;
                ptr=ptr->next;
            }
            // cout<<count<<endl;
            if(count==0)
            temp=temp->next;
            else
            temp->next=ptr;
        }
        return ans->next;
    }
};