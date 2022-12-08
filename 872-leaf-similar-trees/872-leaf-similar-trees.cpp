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
    void ans(TreeNode*root,vector<int>&v)
    {
        if((root->left==NULL)&&(root->right==NULL)){
            v.push_back(root->val);
            return ;
        }
        if(root->left)
        ans(root->left,v);
        if(root->right)
        ans(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>sol1;
        ans(root1,sol1);
        vector<int>sol2;
        ans(root2,sol2);
        
        return sol1==sol2;
    }
};