class Solution {
public:
    bool ans(vector<int>adj[],vector<int>&visited,int src,vector<int>&color){
        visited[src]=1;
        int c = color[src];
        for(auto i:adj[src]){
            if(visited[i]==1 && color[i]==c){
                return false;
            }
            else{
                if(visited[i]==0){
                    color[i] = !c;
                    if(ans(adj,visited,i,color)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& v) {
        vector<int>adj[n+1];
        for(auto i:v){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>visited(n+1);
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(visited[i]==0 ){
                color[i]=1;
                if(ans(adj,visited,i,color)==false)
                return false;
            }
        }
        return true;
    }
};