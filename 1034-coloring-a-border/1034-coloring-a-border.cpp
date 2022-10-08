class Solution {
public:
    void dfs(vector<vector<int>>&v,int r,int c,int x,vector<vector<int>>&visited,int k){
        if(r<0 || c<0 || r==v.size() || c==v[0].size() || visited[r][c]==1 || v[r][c]!=k){
            return; //
        }
        int count=0; //for non color count;
        if(r-1>=0 && v[r-1][c]==k){
            count++;
        }
        if(r+1<v.size() && v[r+1][c]==k){
            count++;
        }
        if(c-1>=0 && v[r][c-1]==k){
            count++;
        }
        if(c+1<v[0].size() && v[r][c+1]==k){
            count++;
        }
        
        visited[r][c]=1;
        dfs(v,r+1,c,x,visited,k);
        dfs(v,r-1,c,x,visited,k);
        dfs(v,r,c+1,x,visited,k);
        dfs(v,r,c-1,x,visited,k); 
        //all 4 directionally call
        if(count!=4){
            v[r][c]=x; //atlast we have to do because vo change pahele hee karoge to dikkat ho jayega
        }  
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& v, int r, int c, int x) {
        int m = v.size();
        int n=v[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        dfs(v,r,c,x,visited,v[r][c]);
        return v;
    }
};