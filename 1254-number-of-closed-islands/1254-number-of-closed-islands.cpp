class Solution {
public:
    void dfs(vector<vector<int>>&v,int i,int j,vector<vector<int>>&visited,int &flag){
        if(i>=0 && j>=0 && j<v[0].size() && i<v.size() && (v[i][j]==1||visited[i][j])){
            return;
        }
        if(i<0 || j<0 || j==v[0].size() || i == v.size() ){
            flag=0;
            return;
        }
        visited[i][j]=1;
        dfs(v,i+1,j,visited,flag);
        dfs(v,i-1,j,visited,flag);
        dfs(v,i,j-1,visited,flag);
        dfs(v,i,j+1,visited,flag);
    }
    int closedIsland(vector<vector<int>>& v) {
        int m=v.size();
        int n = v[0].size();
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && v[i][j]==0){
                    int flag=1;
                    dfs(v,i,j,visited,flag);
                    count+=flag;
                }
            }
        }
        return count;
    }
};