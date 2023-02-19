struct seg{
    vector<int>tree;

    vector<int>lazy;
    seg(int n){
        vector<int>t(n*4);
        vector<int>l(n*4);
        tree=t;
        lazy=l;
    }
    void propogate(int node,int start,int end){
        if(lazy[node]==0){
            return;
        }
        if(start==end){
            tree[node] = !tree[node];
        }
        else{
                int x = tree[node];
                tree[node] =((end-start+1) - x);
                lazy[node*2] = !lazy[node*2];
                lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = 0;
    }
    void update(int node,int start,int end,int l,int r){
        propogate(node,start,end);
        if(start>r || end<l){
            return;
        }
        if(start==end){
            lazy[node] = !lazy[node];
            propogate(node,start,end);
        }
        else if(start>=l && end<=r){
            lazy[node] = !lazy[node];
            propogate(node,start,end);
        }
        else{
            int mid = (end+start)/2;
            update(2*node,start,mid,l,r);
            update(2*node+1,mid+1,end,l,r);
            tree[node] = tree[node*2] + tree[node*2+1]; 
        }
    }

    int query(int node,int start,int end,int l,int r){
        propogate(node,start,end);
        if(start>r || end<l){
            return 0;
        }
        if(start==end){
            return tree[node];
        }
        else if(start>=l && end<=r){
            return tree[node];
        }
        else{
            int mid = (end+start)/2;
            int x = query(node*2,start,mid,l,r);
            int y = query(node*2+1,mid+1,end,l,r);
            return x+y;
        }

    }
//
};
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long int sum=0;
        for(auto &i:nums2){
            sum+=i;
        }
        int n=nums1.size();
        seg s = seg(n);
        for(int i=0;i<n;i++){
            if(nums1[i])
            s.update(1,0,n-1,i,i);
        }
        vector<long long int>ans;
        for(auto &i:queries){
            if(i[0]==1){
                s.update(1,0,n-1,i[1],i[2]);
            }
            else if(i[0]==2){
                sum+=(long long int)((long long int)(s.query(1,0,n-1,0,n-1)*(long long int)i[1]));
            }
            else{
                ans.push_back(sum);
            }
        }
        return ans;
            
    }
};