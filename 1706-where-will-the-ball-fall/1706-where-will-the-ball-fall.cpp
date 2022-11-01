class Solution {
public:
    void dfs(vector<vector<int>>&v,int i,int j,char x,int &ans){
        if(i<0 || j<0 || j==v[0].size()){
            return;
        }
        if(i==v.size()){
            ans = j;
            return;
        }
        if(x=='L' && v[i][j]==1){
            return;
        }
        else if(x=='R' && v[i][j]==-1){
            return;
        }
        if(v[i][j]==1 && x=='U'){
            dfs(v,i,j+1,'R',ans);
        }
        if(v[i][j]==1 && x=='R'){
            dfs(v,i+1,j,'U',ans);
        }
        if(v[i][j]==-1 && x=='U'){
            dfs(v,i,j-1,'L',ans);
        }
        if(v[i][j]==-1 && x=='L'){
            dfs(v,i+1,j,'U',ans);
        }
        
    }
    vector<int> findBall(vector<vector<int>>& v) {
        int n=v[0].size();
        int m=v.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int sol=-1;
            // vector<vector<int>>visited(m,vector<int>(n,0));
            dfs(v,0,i,'U',sol);
            ans.push_back(sol);
        }
        return ans;
    }
};