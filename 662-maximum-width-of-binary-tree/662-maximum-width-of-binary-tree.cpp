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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,0});
        unsigned long long int ans = 0;
        while(q.size()){
            unsigned long long x = q.size();
            unsigned long long int mn;
            unsigned long long int mx;
        for(int i=0;i<x;i++){
            auto it = q.front();
            q.pop();
            if(it.first->left){
                q.push({it.first->left,(2*it.second+1)});
            }
            if(it.first->right){
                q.push({it.first->right,(2*it.second+2)});
            }
            if(i==0){
                mn=it.second;
            }
            if(i==x-1){
                mx = it.second;
            }
        }
            // cout<<mx<<" "<<mn<<endl;
            ans = max(ans,mx-mn+1);
        }
    
        return ans;
    
    }
};