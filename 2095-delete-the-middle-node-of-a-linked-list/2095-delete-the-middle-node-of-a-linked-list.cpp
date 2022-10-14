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
    ListNode* deleteMiddle(ListNode* head) 
    {
     int count=0;
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            count++;
        }
        if(count==1)
        {
            return NULL;
        }
        else
        {
        ListNode* ptr=head;
        ListNode* temp=new ListNode();
        for(int i=1;i<(count/2)+1;i++)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=NULL;
        return head;
        }
    }
};