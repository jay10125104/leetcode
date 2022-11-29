class Solution {
public:
    // int dp[400001][3];
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(100001,vector<int>(3,INT_MIN));
        dp[0][0]=0;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<3;j++){
                dp[i][j]=dp[i-1][j];
                dp[i][j] = max(dp[i][j],nums[i-1]+dp[i-1][(j+nums[i-1])%3]);
            }
        }
        return dp[n][0];
    }
};