/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode*p,vector<int>&v){
        if(!p){
            v.push_back(-1);
            return;
        }
        v.push_back(p->val);
        inorder(p->left,v);
        inorder(p->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1;
        vector<int>v2;
        inorder(p,v1);
        inorder(q,v2);
        return v1==v2;
    }
};