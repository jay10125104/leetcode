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
struct Segtree
{
    vector<int> v;
    vector<int>tree;
    Segtree(vector<int> arr)
    {
        v = arr;
        int n=v.size();
        vector<int> t(4 * n);
        tree = t;
    }
    void build(int node, int start, int end)
    {
        //start with node 1 ->> call for  start and end.
        // if start and end are equal then we have a single node;
        //therefore tree[node] = v[start];
        //else we call for left->mid; and mid+1 -> right;
        if (start == end)
        {
            tree[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        int left = 2 * node;
        int right = 2 * node + 1;
        build(left, start, mid);
        build(right, mid + 1, end);
        tree[node] = max(tree[left],tree[right]);
    }
    int query(int node, int l, int r, int start, int end)
    {
        // if end < startidx of query or start>endidx of query
        //return -1;
        if (end < l || start > r)
        {
            return -1;
        }
        //if start==end
        //retrun tree[node];
        if (start == end)
        {
            return tree[node];
        }
        // if start and end in middle 
        //return tree[node];
        else if (start >= l && end <= r)
        {
            return tree[node];
        }
        else
        {
            //call for start->mid with node->number 2*node;
            // mid+1->end; with node number -> 2*node+1;
            int mid = (start + end) / 2;
            int left = query(node * 2, l, r, start, mid);
            int right = query(node * 2 + 1, l, r, mid + 1, end);
            return max(left,right); // maxof(left,right);
        }
    }
};
class Solution {
public:
    int starting[100001];
    int ending[100001];
    int arr[200004];
    int t=0;
    void dfs(TreeNode*root,int depth){
        if(!root){
            return;
        }
        // cout<<root->val<<" "<<t<<endl;
        starting[root->val]=t;
        arr[t++]=depth;
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
        ending[root->val]=t++;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        memset(starting,0,sizeof(starting));
        memset(ending,0,sizeof(ending));
        memset(arr,0,sizeof(arr));
        dfs(root,0);
        vector<int>v;
        for(int i=0;i<t;i++){
            v.push_back(arr[i]);
            // cout<<arr[i]<<" ";
        }
        Segtree s=Segtree(v);
        s.build(1,0,t-1);
        vector<int>ans;
        for(auto &i:q){
            int start=starting[i];
            int end=ending[i];
            // cout<<start<<" "<<end<<endl;
            ans.push_back(max(s.query(1,0,start-1,0,t-1),s.query(1,end+1,t-1,0,t-1)));
        }
        return ans;
    }
};