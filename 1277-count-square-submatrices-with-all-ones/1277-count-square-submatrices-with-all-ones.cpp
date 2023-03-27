class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        int dp[m][n];
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=v[i][j];
                }
                else{
                    if(v[i][j])
                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
                }
                // cout<<dp[i][j]<<" ";
                ans+=dp[i][j];
                
            }
            // cout<<endl;
        }
        return ans;
    }
};