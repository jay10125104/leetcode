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
    int ans=INT_MIN;
    int sol(TreeNode*root){
        if(!root){
            return 0;
        }
        else{
            int x = sol(root->left);
            int y = sol(root->right);
            ans = max({ans,x+y+root->val,x+root->val,y+root->val,root->val});
            return max({x+root->val,y+root->val,root->val});
        }
    }
    int maxPathSum(TreeNode* root) {
        ans = max(ans,sol(root));
        return ans;
    }
};