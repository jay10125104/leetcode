class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[100001][2];
        memset(dp,0,sizeof(dp));
        int mod = 1000000007;
        dp[zero][0]=1;
        dp[one][1]=1;
        int ans=0;
        for(int i=0;i<=high;i++){
            if(i-zero>=0){
                dp[i][0] = (dp[i][0]%mod+(dp[i-zero][0]%mod+dp[i-zero][1]%mod)%mod)%mod;
            }
            if(i-one>=0){
                dp[i][1] = (dp[i][1]%mod+(dp[i-one][0]%mod+dp[i-one][1]%mod)%mod)%mod;
            }
            if(i>=low && i<=high){
                ans = (ans%mod + dp[i][0]%mod)%mod;
            ans = (ans%mod + dp[i][1]%mod)%mod;
            }
        }
        
        return ans;
    }
};