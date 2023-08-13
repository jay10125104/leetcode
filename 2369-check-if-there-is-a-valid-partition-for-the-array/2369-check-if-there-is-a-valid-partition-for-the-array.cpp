class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(3,vector<int>(n+1,0));
        dp[0][0]=1;
        dp[1][0]=1;
        dp[2][0]=1;
        for(int i=0;i<nums.size();i++){
            if(i-1>=0 && nums[i]==nums[i-1] && (dp[0][i-1] || dp[1][i-1] || dp[2][i-1])){
                dp[0][i+1] = 1;
            }
            else if(i-2>=0 && nums[i]==nums[i-1] && nums[i-2]==nums[i] && (dp[0][i-2] || dp[1][i-2] || dp[2][i-2])){
                dp[1][i+1] = 1;
            }
            else if((i-2>=0) && (nums[i]==(nums[i-1]+1)) && ((nums[i-1]-1)==(nums[i-2]))  && (dp[0][i-2] || dp[1][i-2] || dp[2][i-2])){
                dp[2][i+1] = 1;
            }
        }
        return dp[0][n] || dp[1][n] || dp[2][n];
    }
};