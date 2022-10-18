class Solution {
public:
    struct dis{
        vector<int>rank;
        vector<int>parent;
        dis(int n){
            vector<int>p(n);
            vector<int>r(n);
            for(int i=0;i<n;i++){
                r[i]=0;
                p[i]=i;
                // cout<<"d";
            }
            rank=r;
            parent = p;
        }
        int find(int u){
            if(u==parent[u]){
                return u;
            }
            else{
                return parent[u] = find(parent[u]);
            }
        }
        bool unionn(int u,int v){
            u = find(u);
            v = find(v);
            if(u==v){
                return true;
            }
            if(rank[u]>rank[v]){
                parent[v] = u;
            }
            else if(rank[u]<rank[v]){
                parent[u]=v;
            }
            else{
                parent[u]=v;
                rank[v]++;
            }
            return false;
        }
    };
    int maximalNetworkRank(int n, vector<vector<int>>& v) {
        vector<int>adj[n];
        dis u = dis(n);
        map<pair<int,int>,int>m;
        for(int i=0;i<v.size();i++){
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
            m[{v[i][0],v[i][1]}]=1;
            m[{v[i][1],v[i][0]}]=1;
            // u.unionn(v[i][0],v[i][1]);
            // cout<<i<<" ";
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int flag=(m[{i,j}]);
                int mid = adj[i].size()+adj[j].size()-flag;
                ans=max(ans,mid);
            }
        }
        return ans;
    }
};