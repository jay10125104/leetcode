class Solution {
public:
    long long getDescentPeriods(vector<int>& v) {
        long long int ans=0;
        int n=v.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        ans = 1;
        for(int i=1;i<n;i++){
            if((-v[i]+v[i-1])==1){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i]=1;
            }
            ans+=(dp[i]);
        }
        return ans;
    }
};