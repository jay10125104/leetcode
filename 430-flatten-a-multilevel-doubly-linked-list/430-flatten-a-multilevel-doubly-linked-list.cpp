/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    queue<int>q;
    void ans(Node*head){
        if(!head){
            return;
        }
        q.push(head->val);
        ans(head->child);
        ans(head->next);
    }
    Node* flatten(Node* head) {
        ans(head);
        if(q.size()==0){
            return NULL;
        }
        int x=q.front();
        q.pop();
        Node*ans = new Node(x);
        ans->next=NULL;
        ans->prev=NULL;
        ans->child=NULL;
        Node*sol=ans;
        while(q.size()){
            int x =q.front();
            q.pop();
            Node*temp = new Node(x);
            temp->next=NULL;
            temp->prev=NULL;
            temp->child=NULL;
            ans->next=temp;
            temp->prev=ans;
            ans=ans->next;
        }
        
        // head=sol->next;
        return sol;
    }
};