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
    vector<int> sol(TreeNode*root){
        
        if(root==NULL){
            return {INT_MAX,INT_MIN,0};
        }
        if(!(root->left)&&!(root->right)){
            ans=max(ans,root->val);
            return {root->val,root->val,root->val};
        }
        
        vector<int>left = sol(root->left);
        vector<int>right=sol(root->right);
        int mn=max(left[0],left[1]);
        int mx=min(right[0],right[1]);
        if(!root->right){
            right={-1,root->val,0};
            mx=root->val+1;
        }
        if(!root->left){
            left={root->val,-1,0};
            mn=root->val-1;
            
            
        }
        if(mn<root->val&&mx>root->val){
            ans=max(ans,root->val+left[2]+right[2]);
            return {left[0],right[1],root->val+left[2]+right[2]};
        }
        else{
            return {INT_MIN,INT_MAX,root->val};
        }
    }
    int maxSumBST(TreeNode* root) {
        sol(root);
        return max(0,ans);
    }
};