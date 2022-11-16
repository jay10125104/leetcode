class Solution {
public:
    int mctFromLeafValues(vector<int>& v) {
        int n=v.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i][j] = INT_MAX;
                if(i==j){
                    dp[i][j] = 0;
                }
                else if((i+1)==j){
                    dp[i][j]=v[i]*v[j];
                }
                else{
                    for(int k=i;k<j;k++){
                        int mx1 = 0;
                        int mx2 = 0;
                        for(int t = i;t<=k;t++){
                            mx1 = max(mx1,v[t]);
                        }
                        for(int t=k+1;t<=j;t++){
                            mx2 = max(mx2,v[t]);
                        }
                        // cout<<mx1<<" "<<mx2<<" "<<i<<" "<<j<<" "<<endl;
                        dp[i][j] = min(dp[i][j],(mx1*mx2)+dp[i][k] + dp[k+1][j]);
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[0][n-1];
    }
};