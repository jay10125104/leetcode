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
    TreeNode*ans(vector<int>&nums,int low,int high){
        if(low>high){
            return NULL;
        }
        else{
            int mid = (low+high)/2;
            TreeNode*sol = new TreeNode(nums[mid]);
            sol->left = ans(nums,low,mid-1);
            sol->right=ans(nums,mid+1,high);
            return sol;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ans(nums,0,nums.size()-1);
    }
};