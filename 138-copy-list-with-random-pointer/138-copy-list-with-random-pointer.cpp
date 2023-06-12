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
       map<Node*,Node*>m;
       map<Node*,Node*>m1;
        Node*ans = new Node(-1);
        Node*sol = ans;
        Node*temp=head;
        while(temp){
            Node*t = new Node(temp->val);
            ans->next = t;
            ans=ans->next;
            m[ans]=temp;
            m1[temp]=ans;
            temp=temp->next;
        }
        
        sol=sol->next;
        Node*temp1=sol;
        Node*temp2=head;
        while(temp2!=NULL){
            Node*mid = m[temp1];
            // cout<<mid->val<<endl;
            temp1->random = m1[mid->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return sol;
        
    }
};