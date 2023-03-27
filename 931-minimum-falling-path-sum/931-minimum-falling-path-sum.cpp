class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j]=v[i][j];
                    
                }
                else{
                    dp[i][j] = dp[i-1][j]+v[i][j];
                    if((j+1)<n){
                        dp[i][j] = min(dp[i][j],dp[i-1][j+1]+v[i][j]);
                    }
                    if((j-1)>=0){
                        dp[i][j] = min(dp[i][j],dp[i-1][j-1]+v[i][j]);
                    }
                    
                }
                if(i==n-1)
                ans = min(ans,dp[i][j]);
            }
        }
        return ans;
        
    }
};