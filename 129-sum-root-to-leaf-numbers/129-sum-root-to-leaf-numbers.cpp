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
    string mid="";
    long long int sol=0;
    void ans(TreeNode*root){
        // cout<<mid<<" ";
        if(!root){
            return;
        }
        mid.push_back((root->val + '0'));
        // cout<<mid;
        ans(root->left);
        ans(root->right);
        if(root->left==NULL && root->right==NULL){
            // cout<<mid<<" ";
            sol+=(stoi(mid));
        }
        mid.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        ans(root);
        return sol;
    }
};