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
   int sol=INT_MAX;
    void ans(TreeNode*root){
        if(!root){
            return;
        }
        TreeNode*temp1 = root->left;
        int mn=INT_MIN;
        while(temp1){
            mn=max(mn,temp1->val);
            temp1 = temp1->right;
        }
        if(mn!=INT_MIN)
        sol = min(sol,abs(mn-root->val));
        TreeNode*temp2 = root->right;
        int mx=INT_MAX;
        while(temp2){
            mx=min(mx,temp2->val);
            temp2 = temp2->left;
        }
        if(mx!=INT_MAX)
        sol = min(sol,abs(root->val-mx));
            ans(root->left);
            ans(root->right);
        // cout<<sol<<" "
       
        
        
    }
    int getMinimumDifference(TreeNode* root) {
        // long lont x=INT_MIN,y=INT_MAX;
        ans(root);
        return sol;
    }
};