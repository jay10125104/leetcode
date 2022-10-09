class Solution {
    
public:
    void dfs(vector<vector<int>>&v,int i,int j,vector<vector<int>>&visited,queue<pair<int,int>>&q){
        if(i<0||j<0||i==v.size()||j==v[0].size()||visited[i][j]||v[i][j]==0){
            return;
        }
        q.push({i,j});
        visited[i][j]=1;
        dfs(v,i+1,j,visited,q);
        dfs(v,i,j-1,visited,q);
        dfs(v,i,j+1,visited,q);
        dfs(v,i-1,j,visited,q);
    }
    int shortestBridge(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    dfs(v,i,j,visited,q);
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        int count=0;
        while(q.size()){
            int x = q.size();
            while(x--){
                auto it=q.front();
                int i=it.first;
                int j=it.second;
                q.pop();
                if(v[i][j]==1 && count){
                    return count-1;
                }
                if(i-1>=0 && visited[i-1][j]==0){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                if(i+1<v.size() && visited[i+1][j]==0){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
                if(j-1>=0 && visited[i][j-1]==0){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
                if(j+1<v[0].size() && visited[i][j+1]==0){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
            }
            count++;
        }
        return count-1;
        
    }
};