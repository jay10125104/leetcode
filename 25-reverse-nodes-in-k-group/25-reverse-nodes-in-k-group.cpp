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
    ListNode* reverseKGroup(ListNode*&head, int k) {
        ListNode* n= head;
        for(int i = 0; i < k; i++){
            if(n == NULL){ return head;}
            n = n->next;
        }
        ListNode *prevptr = NULL;
        ListNode *currptr = head;
        ListNode *nextptr;
        int count = 0;
        while(currptr!=NULL && count<k){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if(nextptr!=NULL){
           head->next = reverseKGroup(nextptr,k); 
        }
        return prevptr;
    }
};