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
    bool ans(TreeNode*root,map<int,int>&m,int k){
        if(!root){
            return false;
        }
        if(m[k - root->val]){
            return true;
        }
        m[root->val] = 1;
        return ans(root->left,m,k)||ans(root->right,m,k);
        
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>m;
        return ans(root,m,k);
        
    }
};