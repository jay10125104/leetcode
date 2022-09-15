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
    pair<int,int> ans(TreeNode*root,int &sol){
        if(root==NULL){
            return {0,0};
        }
        else{
            auto x = ans(root->left,sol);
            auto y = ans(root->right,sol);
            int include = root->val + x.second + y.second;
            int exclude = max(x.first,x.second) + max(y.first,y.second);
            return {include,exclude};
            
        }
    }
    int rob(TreeNode* root) {
        int sol=0;
        auto x = ans(root,sol);
        return max(x.first,x.second);
        return 0;
    }
};