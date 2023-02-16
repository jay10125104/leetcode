class Solution {
public:
    int ans(vector<int>&nums,int target,int idx){
        if(idx==-1){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        int x = ans(nums,target-nums[idx],idx);
        int y = ans(nums,target,idx-1);
        return x+y;
    }
    long long int combinationSum4(vector<int>& nums, int target) {
        vector<double>dp(target+1,0);
        dp[0]=1;
        for(int j=1;j<=target;j++){
        for(auto i:nums){
                if(j>=i){
                    dp[j] = dp[j]+dp[j-i];
                }
            }
            // cout<<dp[j]<<" ";
        }
        return dp[target];
    }
};