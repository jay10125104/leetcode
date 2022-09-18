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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        stack<int>s;
        // s.push(root);
        int count=0;
        while(q.size()){
            int x = q.size();
            // stack<TreeNode*>h;
            while(x--){
                TreeNode*mid = q.front();
                q.pop();
                if(mid->left){
                    q.push(mid->left);
                }
                if(mid->right){
                    q.push(mid->right);
                }
                if(count%2==0){
                    if(mid->left){
                        // cout<<mid->left->val<<" ";
                    s.push(mid->left->val);
                }
                if(mid->right){
                     // cout<<mid->right->val<<" ";
                    s.push(mid->right->val);
                }   
                }
                else{
                    // cout<<s.size()<<" "<<s.top()->val<<" ";
                    // cout<<mid->val<<" "<<s.top()->val<<endl;
                    mid->val = s.top();
                    s.pop();
                }
            }
           
            // s = h;
            count++;
            
        }
        return root;
    }
};