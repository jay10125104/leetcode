class Solution {
public:
    void bfs(vector<int>adj[],int src,int &edge,int &vertex,vector<int>&visited){
        queue<int>q;
        q.push(src);
        visited[src]=1;
        while(q.size()){
            int x = q.front();
            q.pop();
            for(auto it:adj[x]){
                edge++;
                if(visited[it]==0){
                    vertex++;
                    visited[it]=1;
                    q.push(it);
                }
            }
            // cout<<q.size();
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        vector<int>adj[n];
        for(auto i:v){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n);
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                int edge=0;
                int vertex=1;
                bfs(adj,i,edge,vertex,visited);
                // cout<<edge<<" "<<vertex<<endl;
                int extra = vertex-1;
                ans+=((edge/2)-extra);
                count++;
            }
        }
        if(ans>=(count-1)){
            return count-1;
        }
        else{
            return -1;
        }
    }
};