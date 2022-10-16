class Solution {
public:
    struct unionfind{
    int n;
    vector<int>rank;
    vector<int>parent;
    unionfind(int n){
        rank.resize(n);
        fill(rank.begin(),rank.end(),0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        else{
            return parent[node] = find(parent[node]);
        }
    }
    void Union(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v){
            return;
        }
        else{
            parent[u]=v;
            rank[v]+=rank[u];
        }
        
    }
};
    int countServers(vector<vector<int>>& v) {
        int m=v.size();
        int n = v[0].size();
        unionfind u = unionfind(m*n);
        for(int i=0;i<m;i++){
            int prev = -1;
            for(int j=0;j<n;j++){
                int k = (i*n) + j;
                if(v[i][j]){
                    if(prev==-1){
                        prev = k;
                    }
                    else{
                        u.Union(prev,k);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            int prev = -1;
            for(int j=0;j<m;j++){
                int k = (i) + (j)*n;
                // cout<<i<<" "<<j<<" "<<k<<" ";
                if(v[j][i]){
                    if(prev==-1){
                        prev = k;
                    }
                    else{
                        u.Union(prev,k);
                        // cout<<k<<" ";
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i*n+j<<" ";
                if(v[i][j] && u.parent[i*n+j]==(i*n+j) && u.rank[i*n+j]>1){
                    // cout<<i*m+j<<" ";
                    ans+=(u.rank[i*n+j]);
                    // cout<<i*m+j<<" ";
                    
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};