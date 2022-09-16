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
    TreeNode*ans(vector<int>&in,vector<int>&post,int si,int ei,int sp,int ep){
        if(si>ei){
            return NULL;
        }
        else{
            int idx=si;
            int x = post[ep];
            while(in[idx]!=x){
                idx++;
            }
            int total = idx-si;
            TreeNode*root = new TreeNode(post[ep]);
            root->left = ans(in,post,si,idx-1,sp,sp+total-1);
            root->right = ans(in,post,idx+1,ei,sp+total,ep-1);
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return ans(in,post,0,n-1,0,n-1);
    }
};