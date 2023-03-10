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
    void ans(TreeNode*root,int k,long long int &count,long long int &sum,map<long long int,int>&m){
        if(!root){
            return;
        }
        else{
            sum+=root->val;
            m[sum]++;
            ans(root->left,k,count,sum,m);
            ans(root->right,k,count,sum,m);
            long long int req = sum-k;
            m[sum]--;
            if(req==0){
                count++;
                count+=m[0];
            }
            else if(m[req]){
                count+=m[req];
                // count+=m[0];
            }
            sum-=root->val;
        }
    }
    int pathSum(TreeNode* root, int k) {
        long long int count=0;
        map<long long int,int>m;
        long long int sum=0;
        ans(root,k,count,sum,m);
        return count;
    }
};