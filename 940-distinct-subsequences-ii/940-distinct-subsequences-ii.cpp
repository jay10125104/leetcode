class Solution {
public:
    int distinctSubseqII(string s) {
        long long int n=s.size();
        vector<long long int>dp(n+1,0);
        dp[0]=1;
        int MOD=1000000007;
        vector<long long int>prev(26,-1);
        for(int i=1;i<=n;i++){
            char x = s[i-1];
            dp[i] = (dp[i-1]%MOD + dp[i-1]%MOD)%MOD;
            if(prev[x-'a']!=-1){
                dp[i] = (dp[i]%MOD - dp[prev[x-'a']]%MOD + MOD)%MOD;
            }
            prev[x-'a'] = i-1;
        }
        // for(auto i:dp){
        //     cout<<i<<" ";
        // }
        return ((dp[n]-1)+MOD)%MOD;
    }
};