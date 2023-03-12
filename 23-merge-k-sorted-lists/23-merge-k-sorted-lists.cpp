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
    ListNode *merge(ListNode*head1,ListNode*head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        ListNode*head=NULL;
        if(head1->val < head2->val){
            head = head1;
            head->next=merge(head1->next,head2);
        }
        else{
            head= head2;
            head->next = merge(head1,head2->next);
            
        }
        return head;

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode*temp = lists[0];
        for(int i=1;i<lists.size();i++){
            temp = merge(temp,lists[i]);
        }
        return temp;
    }
};