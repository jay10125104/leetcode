struct Segtree
{
    vector<int> v;
    vector<int>tree;
    Segtree(vector<int>&arr)
    {
        v = arr;
        int n=v.size();
        vector<int> t(4 * n);
        tree = t;
    }
    void build(int node, int start, int end)
    {
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
    int query(int node, int l, int r, int start, int end,int x)
    {
        // if end < startidx of query or start>endidx of query
        //return -1;
        if (end < l || start > r)
        {
            return -1;
        }
        if(tree[node]<x){
            return -1;
        }
        if (start == end)
        {
            return start;
        }
        else
        {
            int mid = (start + end) / 2;
            int right = query(node*2+1,l,r,mid+1,end,x);
            if(right==-1){
                return query(node*2,l,r,start,mid,x);
            }
            return right;
        }
    }
};
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        Segtree se = Segtree(nums);
        int ans=0;
        se.build(1,0,n-1);
        int idx=  n;
        for(int i=0;i<n;i++){
            int idx = se.query(1,i,n-1,0,n-1,nums[i]);
                ans = max(ans,idx-i);
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};