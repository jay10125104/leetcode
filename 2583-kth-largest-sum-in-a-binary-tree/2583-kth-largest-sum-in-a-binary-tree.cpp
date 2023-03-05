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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int>v;
        queue<TreeNode*>q;
        // vector<int>v;
        q.push(root);
        while(q.size()){
            long long int x = q.size();
            long long int sum=0;
            while(x--){
                
                auto t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            v.push_back(sum);
        }
        sort(v.rbegin(),v.rend());
        // cout<<v.size();
       if(v.size()<k){
           return -1;
       }
        else{
            return v[k-1];
        }
        return -1;
    }
};