class Solution {
public:
    bool isMatch(string s, string t) {
        s = 'a'+s;
        t = 'a'+t;
        int n=s.size();
        int m=t.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[m][n]=1;
        for(int i=m-1;i>=0;i--){
            if(t[i]=='*'){
                dp[i][n]|=dp[i+1][n];
            }
            for(int j=n-1;j>=0;j--){
                
                if(t[i]=='?'){
                    dp[i][j]|=dp[i+1][j+1];
                }
                else if(t[i]=='*'){
                    dp[i][j]|=dp[i+1][j];
                    dp[i][j]|=dp[i][j+1];
                    dp[i][j]|=dp[i+1][j+1];
                }
                else if(s[j]==t[i]){
                    dp[i][j]|=dp[i+1][j+1];
                }
            }
           
        }
        
        return dp[0][0];
    }
};