class Solution {
public:
    bool isScramble(string s, string t) {
        // int m=s.size();
        int n=t.size();
        int dp[n][n][n+1];
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=n;len++){
            for(int i=0;i<=(n-len);i++){
                for(int j=0;j<=(n-len);j++){
                    if(len==1){
                        if(s[i]==t[j]){
                            dp[i][j][len]=1;
                        }
                    }
                    else{
                        for(int part = 1;part<len;part++){
                            if((dp[i][j][part] && dp[i+part][j+part][len-part])||(dp[i][j+len-part][part] && dp[i+part][j][len-part])){
                                dp[i][j][len]=1;
                            }
                        }
                    }
                        // cout<<dp[i][j][len]<<" ";
                }
                // cout<<endl;
            }
            // cout<<endl;
        }
        return dp[0][0][n];
    }
};