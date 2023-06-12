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
    bool isPalindrome(ListNode* head) {
       ListNode*mid = middleNode(head);
        ListNode*rev = reverseList(mid->next);
        mid->next=NULL;
        while(head!=NULL && rev!=NULL){
            if(head->val!=rev->val){
                return false;
            }
            head=head->next;
            rev=rev->next;
            // return true;
        }
        return true;
    }
};