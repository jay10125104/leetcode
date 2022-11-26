class Solution {
public:
    double dp[101][101];
    double ans(vector<int>&nums,int idx,int k){
        if(idx>=nums.size()){
            return 0;
        }
        else if(dp[idx][k]!=0){
            return dp[idx][k];
        }
        else if(k==1){
            int count=0;
            int sum=0;
            for(int i=idx;i<nums.size();i++){
                sum+=nums[i];
                count++;
            }
            return (double)((double)sum/(double)count);
        }
        else{
            int count=0;
            int sum=0;
            double sol = 0.0;
            for(int i=idx;i<nums.size();i++){
                sum+=nums[i];
                count++;
                sol = max(sol,(double)((double)sum/(double)count) + ans(nums,i+1,k-1));
            }
            return dp[idx][k] = sol;
        }
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp,0,sizeof(dp));
        return ans(nums,0,k);
    }
};