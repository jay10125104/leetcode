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
    int maxLevelSum(TreeNode* root) {
       queue<TreeNode*>q;
        int mx = INT_MIN;
        q.push(root);
        int count=1;
        int ans=0;
        while(q.size()){
            int x = q.size();
            int sum=0;
            while(x--){
                auto it = q.front();
                q.pop();
                sum+=it->val;
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            if(mx<sum){
                mx = sum;
                ans=count;
            }
            count++;
        }
        return ans;
    }
};