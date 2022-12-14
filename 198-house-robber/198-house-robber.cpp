class Solution {
public:
    int ans(vector<int>&nums,int idx,vector<int>&dp){
        if(idx == -1){
            dp[idx+1] = 0;
            
            
            return 0;
        }
        if(idx==0){
            dp[idx+1]=nums[0];
            return nums[0];
        }
        if(dp[idx+1]>=0){
            return dp[idx+1];
        }
        int pick = nums[idx] + ans(nums,idx-2,dp);
        int nonpick = ans(nums,idx-1,dp);
        
        int x = max(pick,nonpick);
        dp[idx+1] = x;
        return x;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            int pick  = nums[i];
            if(i>=2){
                pick+=dp[i-2];
            }
            int non = dp[i-1];
            dp[i] = max(pick,non);
            
        }
        
        return dp[nums.size()-1];
        
    }
};