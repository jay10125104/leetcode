
class Solution {
public:
    int minDepth(TreeNode* root) {
      
        if(root==NULL){
            return 0;
        }
        if((!root->left&&root->right)||(!root->right && root->left)){
            return max(minDepth(root->left),minDepth(root->right))+1;
        }
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};