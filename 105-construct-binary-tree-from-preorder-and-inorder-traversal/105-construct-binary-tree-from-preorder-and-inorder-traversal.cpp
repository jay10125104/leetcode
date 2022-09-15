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
    // int idx=0;
    TreeNode*ans(vector<int>&pre,vector<int>&in,int &idx,int start,int end){
        if(start>end){
            return NULL;
        }
        else{
            TreeNode* mid = new TreeNode(pre[idx]);
            // idx++;
            int k;
            for(int i=start;i<=end;i++){
                if(in[i]==mid->val){
                    k = i;
                    break;
                }
            }
            idx++;
            mid->left = ans(pre,in,idx,start,k-1);
            mid->right = ans(pre,in,idx,k+1,end);
            return mid;
        }
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int idx=0;
        int start=0;
        int end = pre.size()-1;
        return ans(pre,in,idx,start,end);
    }
};