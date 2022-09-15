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
    bool ans(TreeNode*root,long long int &prev){
        if(root==NULL){
            return true;
        }
        else{
            bool one = ans(root->left,prev);
            if(one==false){
                return false;
            }
            if(prev>=root->val){
                return false;
            }
            else{
                prev = root->val;
            }
            bool two = ans(root->right,prev);
            if(two==false){
                return false;
            }
            return true;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long int prev = -1e12;
        return ans(root,prev);
    }
};