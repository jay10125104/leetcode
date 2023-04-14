class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        int ans=INT_MIN;
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        reverse(t.begin(),t.end());
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                else if(j==0){
                    dp[i][j]=0;
                }
                else{
                    if(s[i-1]==t[j-1]){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
                }
                ans=max(dp[i][j],ans);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};