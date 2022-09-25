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
    vector<TreeNode*>sol(int start,int end){
        if(start>end){
             TreeNode*mid = NULL;
            vector<TreeNode*>k;
            k.push_back(mid);
            return k;
        }
        if(start==end){
            TreeNode*mid = new TreeNode(start);
            vector<TreeNode*>k;
            k.push_back(mid);
            return k;
        }
        else{
            vector<TreeNode*>soll;
            for(int i=start;i<=end;i++){
                
                vector<TreeNode*>left = sol(start,i-1);
                vector<TreeNode*>right = sol(i+1,end);
                for(auto j:left){
                    for(auto k:right){
                        TreeNode*mid = new TreeNode(i);
                        mid->left = j;
                        mid->right = k;
                        soll.push_back(mid);
                    }
                }
            }
            return soll;
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans;
        return sol(1,n);
        return ans;
    }
};