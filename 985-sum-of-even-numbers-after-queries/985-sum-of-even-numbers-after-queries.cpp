struct seg
{
    vector<int> v;
    vector<int> tree;
    seg(vector<int> &arr)
    {
        v = arr;
        vector<int> t(v.size() * 4);
        tree = t;
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            if(v[start]%2==0){
                tree[node]=v[start];
            }
            else{
                tree[node]=0;
            }
        }
        else
        {
            int mid = (start + end) / 2;
            build(node * 2, start, mid);
            build(node * 2 + 1, mid + 1, end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            int x = v[start]+val;
            // cout<<x<<" ";
            if(x%2){
                tree[node] =0 ;
            }
            else{
                tree[node] = x;
            }
            v[start]+=val;
            return;
        }
        int mid = (start + end) / 2;
        if (mid<idx)
        {
            update(node * 2 + 1, mid + 1, end, idx, val);
        }
        else
        {
            update(node * 2, start, mid, idx, val);
        }
        tree[node] = tree[node*2] + tree[node*2+1];
    }
};
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        seg se = seg(nums);
        int n=q.size();
        se.build(1,0,n-1);
        vector<int>ans;
        // cout<<"ko";
        // cout<<se.tree[1]<<" ";
        for(auto i:q){
            int idx = i[1];
            int val = i[0];
            se.update(1,0,n-1,idx,val);
            // cout<<se.tree[1]<<"o";
            ans.push_back(se.tree[1]);
        }
        return ans;
    }
};