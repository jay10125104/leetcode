class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=v[i][j];
                }
                else if(i==0){
                    dp[i][j] = dp[i][j-1]+v[i][j];
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j]+v[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j]+v[i][j],dp[i][j-1]+v[i][j]);
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[m-1][n-1];
        
    }
};