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
    TreeNode* ans(TreeNode*root,map<int,int>m,vector<TreeNode*>&sol){
        if(root==NULL){
            return NULL;
        }
        root->left = ans(root->left,m,sol);
         root->right = ans(root->right,m,sol);
        if(m[root->val]){
            // root->val = -1;
            if(root->left){
                sol.push_back(root->left);
                // delete(root->)
            }
            if(root->right){
                sol.push_back(root->right);
            }
            return NULL;
            // cout<<"i";
            // root->
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& v) {
        vector<TreeNode*>sol;
        map<int,int>m;
        for(auto i:v){
            m[i] = 1;
        }
        ans(root,m,sol);
        if(m[root->val]==0){
            sol.push_back(root);
        }
        return sol;
    }
};