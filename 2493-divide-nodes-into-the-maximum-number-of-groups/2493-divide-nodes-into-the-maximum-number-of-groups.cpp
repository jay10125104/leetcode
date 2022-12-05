class Solution {
public:
    struct unionfind{
    int n;
    vector<int>parent;
    unionfind(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
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
        parent[u] = v;
    }
    };
    bool bipartite(vector<int>adj[],vector<int>&visited,int src){
        visited[src]=1;
        queue<int>q;
        q.push(src);
        while(q.size()){
            int x = q.size();
            while(x--){
                int t = q.front();
                q.pop();
                int tocolor;
                if(visited[t]==1){
                    tocolor=2;
                }
                else{
                    tocolor=1;
                }
                for(auto &it:adj[t]){
                    if(visited[it]==0){
                        q.push(it);
                        visited[it]=tocolor;
                    }
                    else if(visited[it]==tocolor){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
    int bfs(vector<int>adj[],int src,int n){
        queue<int>q;
        q.push(src);
        vector<int>visited(n+1);
        visited[src]=1;
        int ans=0;
        while(q.size()){
            int x = q.size();
            ans++;
            while(x--){
                int t = q.front();
                q.pop();
                for(auto &it:adj[t]){
                    if(visited[it]==0){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
        }
        return ans;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        unionfind u = unionfind(n+1);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            u.Union(i[0],i[1]);
        }
        vector<int>visited(n+1);
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                if(!bipartite(adj,visited,i)){
                    return -1;
                }
            }
        }
        map<int,int>ans;
        vector<int>dis(n+1);
        for(int i=1;i<=n;i++){
            dis[i]=bfs(adj,i,n);
        }
        for(int i=1;i<=n;i++){
            int x = u.find(i);
            ans[x]=max(ans[x],dis[i]);
        }
        int sol=0;
        for(auto &i:ans){
            sol+=i.second;
        }
        return sol;
    }
};