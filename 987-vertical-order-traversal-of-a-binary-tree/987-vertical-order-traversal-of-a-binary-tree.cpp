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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,vector<int>>m;
        while(q.size()){
            int x = q.size();
            map<int,vector<int>>t;
            while(x--){
                auto mid = q.front();
                q.pop();
                t[mid.second].push_back(mid.first->val);
                if(mid.first->left){
                    q.push({mid.first->left,mid.second-1});
                }
                if(mid.first->right){
                    q.push({mid.first->right,mid.second+1});
                }
            }
            for(auto i:t){
                int x = i.first;
                sort(i.second.begin(),i.second.end());
                for(auto j:i.second){
                    m[x].push_back(j);
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:m){
            // sort(i.second.begin(),i.second.end());
            ans.push_back(i.second);
        }
        return ans;
    }
};