class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        int ans=1;
        // nums[0]=1;
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=1;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};