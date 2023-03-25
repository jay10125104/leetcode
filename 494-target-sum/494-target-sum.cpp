class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }
        target=abs(target);
        sum+=target;
        sum=abs(sum);
        if(sum%2){
            return 0;
        }
        else{
            int n=nums.size();
            sum/=2;
            int dp[n+1][sum+1];
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=sum;j++){
                    int x = nums[i-1];
                    dp[i][j]=dp[i-1][j];
                    if(j-x>=0){
                        dp[i][j]+=dp[i-1][j-x];
                    }
                }
            }
            return dp[n][sum];
        }
    }
};