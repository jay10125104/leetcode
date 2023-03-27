class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n=v.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            int ans = INT_MIN;
            int mx = INT_MIN;
            int count=0;
            for(int j=i;j<min(n,i+k);j++){
                count++;
                mx = max(mx,v[j]);
                ans = max(ans,count*mx);
                if((j+1)<n){
                    ans = max(dp[j+1]+count*mx,ans);
                }
                
            }
            dp[i]=ans;
            cout<<dp[i]<<" ";
        }
        
        return dp[0];
    }
};