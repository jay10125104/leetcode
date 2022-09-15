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
    pair<int,int> sol(TreeNode*root,int &ans){
        if(root==NULL){
            return {0,0};
        }
        else{
            auto x = sol(root->left,ans);
            auto y = sol(root->right,ans);
            if(x.first==0 && x.second==0 && y.first==0 && y.second==0){
                return {1,0};
            }
            else if(x.first==1 || y.first==1){
                ans++;
                return {0,1};
            }
            else{
                return {0,0};
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        if(root!=NULL && root->left==NULL && root->right==NULL){
            return 1;
        }
        int ans=0;
        // pair->{req , has camera};
        auto mid = sol(root,ans);
        // cout<<mid.first<<" "<<mid.second<<endl;
        return ans + mid.first;
    }
};