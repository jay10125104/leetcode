class Solution {
public:
    int parent[100001];
    map<pair<int,int>,int>guess;
    int ans=0;
    void dfs(vector<int>adj[],int src,int parent1){
        parent[src] = parent1;
        for(auto &i:adj[src]){
            if(i!=parent1){
                dfs(adj,i,src);
            }
        }
    }
    void dfs1(vector<int>adj[],int src,int parent,int correct,int k){
        int x = correct;
        if(guess[{parent,src}]){
            x--;
        }
        if(guess[{src,parent}]){
            x++;
        }
        if(x>=k){
            ans++;
        }
        for(auto &i:adj[src]){
            if(i!=parent){
                dfs1(adj,i,src,x,k);
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        for(auto &i:guesses){
            guess[{i[0],i[1]}]++;
        }
        int n=edges.size()+1;
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        memset(parent,0,sizeof(parent));
        dfs(adj,0,0);
        int correct=0;
        for(int i=0;i<n;i++){
            int p = parent[i];
            if(guess[{p,i}]){
                correct++;
            }
        }
        // if(correct>=k){
        //     ans++;
        // }
        dfs1(adj,0,0,correct,k);
        return ans;
        
    }
};