class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>&q) {
        // map<pair<int,int>>m;
        vector<int>adj[n];
        for(auto i:p){
            adj[i[0]].push_back(i[1]);
        }
        vector<vector<int>>visited(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            queue<int>q;
            q.push(i);
            vector<int>vis(n);
            vis[i]=1;
            while(q.size()){
                int x = q.front();
                q.pop();
                for(auto it:adj[x]){
                    if(vis[it]==0){
                        //it its already marked then it is sure that it has already mark them up;
                        vis[it]=1;
                        visited[i][it]=1;
                        q.push(it);
                    }
                }
            }
        }
        vector<bool>sol;
        for(auto i:q){
            if(visited[i[0]][i[1]]){
                sol.push_back(true);
            }
            else{
                sol.push_back(false);                
            }
        }
        return sol;
        
    }
};