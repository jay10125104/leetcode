class Solution {
public:
    int minInsertions(string s) {
        int dp[501][501];
        memset(dp,-1,sizeof(dp));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if((i+1)==j && s[i]==s[j]){
                    dp[i][j]=2;
                }
                else if((i+1)==j){
                    dp[i][j]=1;
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1]+2;
                        continue;
                    }
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return s.size()-dp[0][s.size()-1];
    }
};