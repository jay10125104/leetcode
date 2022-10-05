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
    TreeNode* addOneRow(TreeNode* root, int t, int xy) {
        int currlevel=1;
        xy--;
        if(xy==0){
            TreeNode*temp = new TreeNode(t);
            temp->left = root;
            return temp;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            cout<<currlevel;
            int x = q.size();
            while(x--){
                auto it = q.front();
                q.pop();
                if(currlevel==xy){
                    auto l = it->left; 
                    auto r = it->right;
                    it->left = new TreeNode(t);
                    it->right = new TreeNode(t);
                    it->left->left = l;
                    it->right->right = r;
                    
                }
                
                if(it->left)
                q.push(it->left);
                if(it->right)
                q.push(it->right);
            }
            if(currlevel==xy){
                return root;
            }
            currlevel++;
        }
        return root;
    }
};