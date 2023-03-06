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
    string ans="";
    void dfs(TreeNode*root,string &s){
        if(root==NULL){
            return;
        }
        else{
            s.push_back((char)(root->val+'a'));
            dfs(root->left,s);
            dfs(root->right,s);
            if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            if(ans==""){
                ans=s;
            }
            else if(ans>s){
                ans=s;
            }
            reverse(s.begin(),s.end());
            }
            s.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return ans;
    }
};