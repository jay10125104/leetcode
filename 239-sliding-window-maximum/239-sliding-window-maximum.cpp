
class Solution {
    struct seg{
        vector<int>tree;
        vector<int>v;
        seg(vector<int>&arr){
            v = arr;
            vector<int>t(v.size()*4);
            tree = t;
        }
        void build(int node,int start,int end){
            if(start==end){
                tree[node] = v[start];
            }
            else{
                int mid = (start+end)/2;
                build(node*2,start,mid);
                build(node*2+1,mid+1,end);
                tree[node] = max(tree[node*2],tree[node*2+1]);
            }
        }
        long long int query(int node,int start,int end,int l ,int r){
            if(start>r || end<l){
                return INT_MIN;
            }
            else if(start==end){
                return tree[node];
            }
            else if(start>=l && end<=r){
                return tree[node];
            }
            else{
                int mid = (start+end)/2;
                int x = query(node*2,start,mid,l,r);
                int y =query(node*2+1,mid+1,end,l,r);
                return max(x,y);
            }
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        seg se = seg(v);
        int n = v.size();
        se.build(1,0,n-1);
        vector<int>ans;
        for(int i=0;(i+k)<=v.size();i++){
            int mid = se.query(1,0,n-1,i,i+k-1);
            ans.push_back(mid);
        }
        return ans;
        
    }
};