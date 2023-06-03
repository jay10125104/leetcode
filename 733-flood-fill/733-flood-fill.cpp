class Solution {
public:
    int visited[51][51];
    void dfs(vector<vector<int>>&v,int x,int y,int color){
        if(x<0||y<0||x==v.size()||y==v[0].size()||visited[x][y]==1||v[x][y]!=color){
            return;
        }
        visited[x][y]=1;
        dfs(v,x+1,y,color);
        dfs(v,x-1,y,color);
        dfs(v,x,y+1,color);
        dfs(v,x,y-1,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color) {
        memset(visited,0,sizeof(visited));
        dfs(v,sr,sc,v[sr][sc]);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(visited[i][j]){
                    v[i][j]=color;
                }
            }
        }
        return v;
    }
};