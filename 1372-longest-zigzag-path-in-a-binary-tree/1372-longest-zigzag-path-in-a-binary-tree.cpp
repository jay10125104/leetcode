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
            auto ll = ans(root->left,sol);
            auto rr = ans(root->right,sol);
            sol = max(sol,max({ll.second,ll.first,rr.second,rr.first}));
            return {ll.second+1,rr.first+1};
        }
    }
    int longestZigZag(TreeNode* root) {
        int sol=0;
        auto it = ans(root,sol);
        sol = max(sol,max({it.first,it.second}))-1;
        return sol;
    }
};