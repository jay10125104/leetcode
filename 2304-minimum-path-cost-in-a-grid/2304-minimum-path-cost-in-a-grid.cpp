class Solution {
public:
    int dp[51][51];
    int ans(vector<vector<int>>&v,vector<vector<int>>&c,int row,int col){
        if(row==v.size()-1){
            return v[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int mn = INT_MAX;
        for(int i=0;i<v[0].size();i++){
            mn=min(mn,v[row][col]+ans(v,c,row+1,i)+c[v[row][col]][i]);
        }
        return dp[row][col] = mn;
    }
    int minPathCost(vector<vector<int>>& v, vector<vector<int>>& c) {
        memset(dp,-1,sizeof(dp));
        int sol=INT_MAX;
        for(int i=0;i<v[0].size();i++){
            sol = min(sol,ans(v,c,0,i));
        }
        return sol;
    }
};