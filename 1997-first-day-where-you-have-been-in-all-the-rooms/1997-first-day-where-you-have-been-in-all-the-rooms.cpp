class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& v) {
        long long int n=v.size();
        long long int dp[n];
        long long int ans=1;
        int mod = 1000000007;
        memset(dp,0,sizeof(dp));
        dp[0]=2;
        for(int i=1;i<n-1;i++){
            dp[i] = (dp[i]%mod+dp[i-1]%mod)%mod;
            dp[i]++;
           int prev = (v[i]==0)?(0):(dp[v[i]-1]);
            dp[i]+=(dp[i-1]%mod-prev%mod+1 + mod)%mod;
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        return (dp[n-2]+mod)%mod;
    }
};