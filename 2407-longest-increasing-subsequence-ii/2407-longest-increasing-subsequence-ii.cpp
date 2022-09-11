class Solution {
public:
    struct seg{ 
        vector<int>v;
        vector<int>tree;
        seg(vector<int>&arr){
            v = arr;
            int n=500001;
            vector<int>t(n,0);
            tree=t;
        }
        int query(int node,int start,int end,int l,int r){
            if(start>r || end<l){
                return 0;
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
                int y = query(node*2+1,mid+1,end,l,r);
                return max(x,y);
            }
        }
        void update(int node,int start,int end,int idx,int val){
            if(start==end){
                tree[node] = val;
            }
            else{
                int mid = (start+end)/2;
                if(idx<=mid){
                    update(node*2,start,mid,idx,val);
                }
                else{
                    update(node*2+1,mid+1,end,idx,val);
                }
                tree[node] = max(tree[node*2],tree[node*2+1]);
            }
        }
    };
    int lengthOfLIS(vector<int>& v, int k) {
        seg se = seg(v);
        int ans=0;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            int mid = se.query(1,0,100000,v[i]+1,v[i]+k)+1;
            // cout<<mid<<" ";
            se.update(1,0,100000,v[i],mid);
            // cout<<endl;
            ans = max(ans,mid);
        }
        return ans;
    }
};