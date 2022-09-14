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
    int ans(TreeNode*root,int &flag){
        if(root==NULL){
            return 0;
        }
        int lh = ans(root->left,flag);
        int rh = ans(root->right,flag);
        // cout<<lh<<" "<<rh<<endl;
        if(abs(lh-rh)>=2){
            flag=0;
        }
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        int flag=1;
        ans(root,flag);
        return flag;
    }
};