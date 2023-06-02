class Solution {
public:
    int minDistance(string s, string t) {
        // swap(s,t);
        int m=s.size();
        int n=t.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0){
                    dp[i][j]=0;
                }
                else if(i==0||j==0){
                    dp[i][j]=max(i,j);
                }
                else{
                    if(s[i-1]==t[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[m][n];
    }
};