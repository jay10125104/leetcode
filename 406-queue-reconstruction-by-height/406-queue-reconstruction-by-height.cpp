class seg{
    public:
    vector<int>tree;
    seg(int n){
        vector<int>arr(n*4,0);
        tree = arr;
    }
    void build(int node,int start,int end){
        if(start==end){
            tree[node]=1;
            return;
        }
        int mid = (start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    int search(int node,int start,int end,int req){
        if(start==end){
            return start;
        }
        int mid = (start+end)/2;
        if(req<=tree[node*2]){
            return search(node*2,start,mid,req);
        }
        else{
            return search(node*2+1,mid+1,end,req-tree[node*2]);
        }
    }
    void update(int node,int start,int end,int idx){
        // cout<<start<<" "<<" "<<end<<" "<<node<<"\n";
        if(start==end){
            tree[node]=0;
            return;
        }
        // cout<<"g";
        int mid=(start+end)/2;
        if(idx<=mid){
            update(node*2,start,mid,idx);
        }
        else{
            update(node*2+1,mid+1,end,idx);
        }
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
};
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>>v;
        for(auto i:people){
            v.push_back({i[0],i[1]});
        }
        int n=v.size();
        seg *se = new seg(v.size());
        se->build(1,0,n-1);
        sort(v.begin(),v.end(),cmp);
        cout<<"i";
        vector<pair<int,int>>ans(v.size(),{0,0});
        for(auto i:v){
            int idx = se->search(1,0,n-1,i.second+1);
            // cout<<idx;
            ans[idx] = {i.first,i.second};
            
            se->update(1,0,n-1,idx);
        }
        vector<vector<int>>sol;
        for(auto i:ans){
            vector<int>mid;
            mid.push_back(i.first);
            mid.push_back(i.second);
            sol.push_back(mid);
        }
        return sol;
    }
};