class Solution {
public:
    int visited[51][51];
    void dfs(vector<vector<int>>&v,int x,int y,int color,int ncolor){
        if(x<0||y<0||x==v.size()||y==v[0].size()||visited[x][y]==1||v[x][y]!=color){
            return;
        }
        visited[x][y]=1;
        v[x][y]=ncolor;
        dfs(v,x+1,y,color,ncolor);
        dfs(v,x-1,y,color,ncolor);
        dfs(v,x,y+1,color,ncolor);
        dfs(v,x,y-1,color,ncolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color) {
        memset(visited,0,sizeof(visited));
        dfs(v,sr,sc,v[sr][sc],color);
        return v;
    }
};