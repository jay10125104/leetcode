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
    bool ans(TreeNode*root,int k,int &sum){
        if(root==NULL){
            return false;
        }
        else{
            sum+=root->val;
            bool z = ans(root->left,k,sum);
            bool y = ans(root->right,k,sum);
            bool x = (sum==k && root->left==NULL && root->right==NULL);
            sum-=root->val;
            return x || y || z;
        }
    }
    bool hasPathSum(TreeNode* root, int k) {
        int sum=0;
        return ans(root,k,sum);
    }
};