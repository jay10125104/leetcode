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
    int ans(TreeNode*root,map<int,int>&m,int &mx){
        if(root==NULL){
            return 0;
        }
        else{
            int x = ans(root->left,m,mx);
            int y = ans(root->right,m,mx);
            int total = root->val + x+y;
            m[total]++;
            mx = max(mx,m[total]);
            return total;
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        int mx = INT_MIN;
        ans(root,m,mx);
        vector<int>sol;
        for(auto i:m){
            if(i.second==mx)
            sol.push_back(i.first);
        }
        return sol;
    }
};