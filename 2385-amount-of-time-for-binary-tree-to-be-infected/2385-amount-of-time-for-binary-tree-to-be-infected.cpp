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
    bool ans(TreeNode*root,int x,vector<TreeNode*>&sol){
        if(root==NULL){
            return false;
        }
        else{
            bool t = ((root->val==x) || ans(root->left,x,sol) || ans(root->right,x,sol));
            if(t){
                sol.push_back(root);
            }
            return t;
        }
    }
    int helper(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        int count=-1;
        root->val=-1;
        while(q.size()){
            int x = q.size();
            count++;
            while(x--){
                auto mid=q.front();
                q.pop();
                if(mid->left && mid->left->val!=-1){
                    mid->left->val = -1;
                    q.push(mid->left);
                }
                if(mid->right && mid->right->val!=-1){
                    mid->right->val = -1;
                    q.push(mid->right);
                }
            }
        }
        return count;
    }
    int amountOfTime(TreeNode* root, int val) {
        vector<TreeNode*>sol;
        ans(root,val,sol);
        int soll=0;
        for(int i=0;i<sol.size();i++){
            int mid = i+helper(sol[i]);
            soll = max(soll,mid);
        }
        
        return soll;
    }
};