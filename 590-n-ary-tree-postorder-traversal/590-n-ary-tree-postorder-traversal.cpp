/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void ans(Node*root,vector<int>&sol){
        if(root==NULL){
            return;
        }
        else{
            for(auto i:root->children){
                ans(i,sol);
                
            }
            sol.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
       vector<int>sol;
        ans(root,sol);
        return sol;
    }
};