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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        while(q.size()){
            int x = q.size();
            int counter=0;
            while(x--){
                auto mid = q.front();
                q.pop();
                if(counter==0){
                    ans = mid->val;
                }
                if(mid->left){
                    q.push(mid->left);
                }
                if(mid->right){
                    q.push(mid->right);
                }
                counter++;
            }
            
        }
        return ans;
    }
};