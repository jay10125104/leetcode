class Solution {
private:
    int size[30001];
    int ans[30001];
public:
    int dfs(vector<int>adj[],int src,int parent,int level){
        int sz=0;
        ans[0]+=level;
        for(auto &i:adj[src]){
            if(i!=parent){
                sz+=(dfs(adj,i,src,level+1));
            }
        }
        return size[src] = sz+1;
    }
    void dfs1(vector<int>adj[],int src,int parent,int n){
        for(auto &i:adj[src]){
            if(parent!=i){
                    ans[i] = ans[src]+(n)-(2*size[i]);
                    dfs1(adj,i,src,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
         memset(size,0,sizeof(size));
        memset(ans,0,sizeof(ans));
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(adj,0,-1,0);
        dfs1(adj,0,-1,n);
       
        vector<int>answer;
        for(int i=0;i<n;i++){
            answer.push_back(ans[i]);
        }
        return answer;
    }
    
};