struct seg{
    vector<int>tree;
    seg(int n){
        vector<int>t(n*4);
        tree=t;
    }
    void update(int node,int start,int end,int idx){
        if(start==end){
            tree[node]=1;
        }
        else{
            int mid = (start+end)/2;
            if(idx<=mid){
                update(node*2,start,mid,idx);
            }
            else{
                update(node*2+1,mid+1,end,idx);
            }
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    long long int query(int node,int start,int end,int l,int r){
        if(l>end || r<start){
            return 0;
        }
        else if(start>=l && end<=r){
            return tree[node];
        }
        else{
            int mid=(start+end)/2;
            long long int x = query(node*2,start,mid,l,r);
            long long int y = query(node*2+1,mid+1,end,l,r);
            return x+y;
        }
    }
};
class Solution {
public:
    bool isIdealPermutation(vector<int>& v) {
        long long int count=0;
        for(int i=1;i<v.size();i++){
            count+=(v[i]<v[i-1]);
        }
        int n=v.size();
        seg s = seg(n);
        long long int count1=0;
        for(int i=n-1;i>=0;i--){
            int x = v[i];
            count1+=(s.query(1,0,n-1,0,x-1));
            s.update(1,0,n-1,x);
        }
        return count1==count;
    }
};