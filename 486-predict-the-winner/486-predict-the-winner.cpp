class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
    int dp[n][n];
        int sum=0;
        memset(dp,0,sizeof(dp));
        for(auto &i:nums){
            sum+=i;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j]=nums[i];
                }
                else if((i+1)==j){
                    dp[i][j] = max(nums[i],nums[j]);
                }
                else{
                    dp[i][j] = max(nums[i]+min(dp[i+2][j],dp[i+1][j-1]),nums[j]+min(dp[i+1][j-1],dp[i][j-2]));
                }
            }
        }

        return dp[0][n-1]>=(sum-dp[0][n-1]);
    }
};