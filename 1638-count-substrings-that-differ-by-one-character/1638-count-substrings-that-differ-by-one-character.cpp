class Solution {
public:
    int countSubstrings(string s, string t) {
        int dp[s.size()+2][t.size()+2];
        int dp2[s.size()+2][t.size()+2];
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp2[i][j] = dp2[i+1][j+1]+1;
                }
                // cout<<dp2[i][j]<<" ";
            }
            // cout<<endl;
        }
        int ans=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]!=t[j-1]){
                    int one = (dp[i-1][j-1]);
                    int two = (dp2[i][j]);
                    ans+=one;
                    ans+=two;
                    ans+=(one*two);
                    // int two = (dp[i+1][j+1]);
                    ans++;
                    // cout<<i<<" "<<" "<<j<<" "<<ans<<endl;
                }
            }
        }
        return ans;
    }
};