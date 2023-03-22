class Solution {
public:
    struct Unionfind{
        int parent[100002];
        Unionfind(int n){
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int find(int node){
            if(parent[node]==node){
                return node;
            }
            else{
                return parent[node]=find(parent[node]);
            }
        }
        void Union(int u,int v){
            u = find(u);
            v = find(v);
            parent[v]=u;
        }
    };
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        int mn=INT_MAX;
        Unionfind u = Unionfind(n+1);
        for(auto &i:roads){
            u.Union(i[0],i[1]);
        }
        int req = u.find(1);
        for(auto &i:roads){
            int one = u.find(i[0]);
            int two = u.find(i[1]);
            if(req==one || req==two){
                mn = min(mn,i[2]);
            }
        }
        return mn;
        vector<int>visited(n+1);
        vector<int>dis(n+1,INT_MAX);
        queue<int>q;
        dis[1]=0;
        q.push(1);
        while(q.size()){
            auto it = q.front();
            q.pop();
            int src = it;
            for(auto &i:adj[src]){
                if((dis[src]+i.second)<dis[i.first]){
                    dis[i.first] = dis[src]+i.second;
                    q.push(i.first);
                }
            }
        }
        return dis[n];
    }
};