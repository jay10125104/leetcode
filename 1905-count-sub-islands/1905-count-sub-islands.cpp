class Solution {
public:
    void dfs(vector<vector<int>>&v,vector<vector<int>>&t,int i,int j,vector<vector<int>>&visited,int &flag){
        if(i<0 || j<0 || i==v.size() || j==v[0].size() || visited[i][j] ||v[i][j]==0){
            return;
            
        }
        if(t[i][j]==0){
            flag=0;
        }
        visited[i][j]=1;
        dfs(v,t,i+1,j,visited,flag);
        dfs(v,t,i-1,j,visited,flag);
        dfs(v,t,i,j-1,visited,flag);
        dfs(v,t,i,j+1,visited,flag);
    }
    int countSubIslands(vector<vector<int>>& t, vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] && visited[i][j]==0){
                    int flag=1;
                     dfs(v,t,i,j,visited,flag);
                    count+=flag;
                }
            }
        }
        return count;
    }
};