class Solution {
public:
    int dp[20][1<<10][1<<10];
    int ans(vector<int>&nums,int idx,int k,int mask1,int mask2){
        if(idx==nums.size()){
            return 0;
        }
        else if(dp[idx][mask1][mask2]!=-1){
            return dp[idx][mask1][mask2];
        }
        else{
            int sol=0;
            for(int i=0;i<k;i++){
                if((mask1&(1<<i))==0){
                    sol = max(sol,ans(nums,idx+1,k,mask1|(1<<i),mask2)+(nums[idx]&(i+1)));
                }
                else if((mask2&(1<<i))==0){
                    sol = max(sol,ans(nums,idx+1,k,mask1,mask2|(1<<i))+(nums[idx]&(i+1)));                    
                }
            }
            return dp[idx][mask1][mask2]=sol;
        }
    }
    int maximumANDSum(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return ans(nums,0,k,0,0);
    }
};