/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp = head;
        if(!temp){
            return NULL;
        }
        while(temp){
            Node*mid = new Node(temp->val);
            Node*nxt = temp->next;
            temp->next=mid;
            mid->next=nxt;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            if(temp->random)
            temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
        Node*ans = head;
        while(ans){
            if(ans->random)
            ans->next->random = ans->random->next;
            ans=ans->next->next;
        }
        ans=head;
        Node*sol = ans->next;
        while(ans){
            if(ans->next->next){
                Node*mid=ans->next->next;
                ans->next->next=ans->next->next->next;
                ans->next=mid;
                ans=ans->next;
            }
            else{
                ans->next->next=NULL;
                ans->next=NULL;
                ans=ans->next;
            }
        }
        return sol;
    
        
    }
};