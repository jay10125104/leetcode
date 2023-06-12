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
    ListNode* middleNode(ListNode* head) {
        ListNode*first=head;
        ListNode*second=head;
        while(second && second->next!=NULL && second->next->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        return first;
    }
    ListNode* reverseList(ListNode* head) {
       ListNode*prev=NULL; 
       ListNode*curr=head;
        while(curr!=NULL){
            // cout<<curr->val<<endl;
            ListNode*nxt = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*mid = middleNode(head);
        ListNode*rev = reverseList(mid->next);
        mid->next=NULL;
        ListNode*temp=head;
        while(temp!=NULL && rev!=NULL){
            // cout<<temp->val<<" "<<rev->val<<endl;
            ListNode*temp1 = temp->next;
            ListNode*temp2 = rev->next;
            rev->next=temp->next;
            temp->next = rev;
            temp=temp1;
            rev=temp2;
        }
        // cout<<"asdf";
        
        while(head){
            // cout<<head->val<<" ";
            head=head->next;
        }
        
    }
};