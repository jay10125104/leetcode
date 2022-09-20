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
    long long int mod=1000000007;
    long long int sum(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        else{
            long long int x = sum(root->left);
            long long int y = sum(root->right);
            return x+y+root->val;
        }
    }
    long long int ans(TreeNode*root,long long int summ,long long int &sol){
        if(root==NULL){
            return 0;
        }
        else{
            long long int x = ans(root->left,summ,sol);
            long long int y = ans(root->right,summ,sol);
                sol = max(sol,((x)*(summ-x)));
                sol = max(sol,((y)*(summ-y)));
                // sol = max(sol,((y%mod)*(summ-y)%mod + mod)%mod);
                // cout<<sol<<" ";
            return x+y+root->val;
        }
    }
    int maxProduct(TreeNode* root) {
        long long int summ = sum(root);
        long long int mn = 0;
        ans(root,summ,mn);
        return mn%mod;
    }
};