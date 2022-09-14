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
    int ans(TreeNode*root,int &sol){
        if(root==NULL){
            return 0;
        }
        else{
            int x = ans(root->left,sol);
            int y = ans(root->right,sol);
            sol+=abs(x-y);
            return x+y+root->val;
        }
    }
    int findTilt(TreeNode* root) {
        int sol=0;
        ans(root,sol);
        return sol;
    }
};