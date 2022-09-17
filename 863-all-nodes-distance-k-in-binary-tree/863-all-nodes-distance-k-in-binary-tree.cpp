/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool sol(TreeNode*root,int target,vector<TreeNode*>&ans){
        if(!root){
            return false;
        }
        bool x = (root->val == target)||(sol(root->left,target,ans) || sol(root->right,target,ans));
        if(x==true){
            ans.push_back(root);
        }
        return x;
    }
    void helper(TreeNode*it,vector<int>&mid,int distance){
        if(it==NULL || it->val==-1){
            return;
        }
        else if(distance==0){
            mid.push_back(it->val);
            return;
        }
        else{
            helper(it->left,mid,distance-1);
            helper(it->right,mid,distance-1);
            it->val=-1;
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*>ans;
        int t = target->val;
        sol(root,t,ans);
        vector<int>mid;
        for(int i=0;i<ans.size();i++){
            auto it = ans[i];
            int distance = k-i;
            helper(it,mid,distance);
            
        }
        return mid;
    }
};