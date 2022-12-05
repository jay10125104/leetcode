class Solution {
public:
    int longestArithSeqLength(vector<int>&nums) {
        int ans=0;
        int n=nums.size();
        int dp[1001][1002];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int diff = 500+nums[i]-nums[j];
                int x = dp[j][diff];
                if(x!=0){
                    dp[i][diff] = max(dp[i][diff],x+1);
                }
                else{
                    dp[i][diff]=max(dp[i][diff],2);
                }
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};