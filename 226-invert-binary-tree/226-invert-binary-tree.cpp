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
    TreeNode*ans(TreeNode*root){
        if(root==NULL){
            return NULL;
        }
        // cout<<root->val<</endl;
        TreeNode*r=root->right;
        TreeNode*l=root->left;
        root->left = ans(r);
        root->right=ans(l);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return ans(root);
    }
};