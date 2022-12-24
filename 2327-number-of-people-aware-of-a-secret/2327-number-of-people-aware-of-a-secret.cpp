class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int mod = 1000000007;
        for(int i=0;i<n;i++){
            for(int j=delay;j<forget && ((i+j)<n);j++){
                dp[i+j] = (dp[i]%mod+dp[i+j]%mod)%mod;
            }
        }
        int i=n-1;
        int ans=0;
        while(i>=0 && forget){
            forget--;
            ans= (ans%mod + dp[i]%mod)%mod;
            i--;
        }
        return ans;
        
    }
};