class Solution {
public:
    int mctFromLeafValues(vector<int>& v) {
        int n=v.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int mx[n][n];
        memset(mx,0,sizeof(mx));
        for(int i=n-1;i>=0;i--){
            int mn=0;
            for(int j=i;j<n;j++){
                mn = max(mn,v[j]);
                mx[i][j]=mn;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i][j] = INT_MAX;
                if(j==i){
                    dp[i][j]=0;
                }
                else{
                    for(int k=i;k<j;k++){
                        dp[i][j] = min(dp[i][j],mx[i][k]*mx[k+1][j]+dp[i][k]+dp[k+1][j]);
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[0][n-1];
    }
};