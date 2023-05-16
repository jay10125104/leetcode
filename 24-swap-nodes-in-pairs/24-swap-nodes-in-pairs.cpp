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
   int length(ListNode *n){
       int count=0;
       while(n!=NULL){
           count++;
           n = n->next;
       }
       return count;
   }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextptr;
        int ans = 0;
        int count = 2;
        if(length(head)==0){
            return NULL;
        }
   
        while(curr!=NULL && count--){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            
        }
        if(nextptr!=NULL){
            head->next = swapPairs(nextptr);
        }
        return prev;
    }
};