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
    long long int length(ListNode* n){
        int count=0;
        while(n!=NULL){
            n=n->next;
            count++;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, long long int k) {
        ListNode *n=head;
        ListNode *temp=head;
        long long int backnode = length(head)-k;
        while(--k){
            n=n->next;
            }
        while(backnode--){
            temp=temp->next;
        }
        long long int dup = n->val;
        n->val = temp->val;
        temp->val = dup;
        
        return head;
    }
};