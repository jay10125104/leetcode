class Solution {
public:
    int dp[100001];
    int ans(vector<int>&nums,int idx)
    {
        if(idx>=nums.size()-1){
            return 1;
        }
        // else if
        else if(dp[idx]!=-1){
            return dp[idx];
        }
        else{
            
            for(int i=1;i<=nums[idx];i++){
                if(ans(nums,idx+i)){
                    return dp[idx]=1;
                }
            }
            return dp[idx] = 0;
        }
        
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        if(ans(nums,0)){
            return true;
        }
        else{
            return false;
        }
    }
};