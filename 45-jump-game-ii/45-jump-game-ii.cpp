class Solution {
public:
    int dp[10001];
    int ans(int idx,vector<int>&nums){
        if(idx>=nums.size()-1){
            return 0;
        }
        else if(dp[idx]!=-1){
            return dp[idx];
        }
        else{
            int steps = 1e9;
            for(int i=1;i<=nums[idx];i++){
                steps = min(steps,1+ans(idx+i,nums));
            }
            return dp[idx] = steps;
        }
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return ans(0,nums);
    }
};