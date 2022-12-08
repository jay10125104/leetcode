class Solution {
public:
    int dp[17][1<<16];
    bool ans(vector<int>&nums,int count,int k,int mask,int target){
        if(count==k){
            return true;
        }
        else if(dp[count][mask]!=-1){
            return dp[count][mask];
        }
        else{
            int t = pow(2,nums.size());
            for(int i=0;i<t;i++){
                if(mask&i){
                    continue;
                }
                int sum=0;
                int t = i;
                int counter=0;
                while(t){
                    if(t&1){
                        sum+=nums[counter];
                    }
                    if(sum>target){
                        break;
                    }
                    counter++;
                    t =t/2;
                }
                if(sum==target){
                    if(ans(nums,count+1,k,mask|i,target)){
                        return dp[count][mask]= true;
                    }
                }
            }
            return dp[count][mask] = false;
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }
        if(sum%k){
            return 0;
        }
        else{
            memset(dp,-1,sizeof(dp));
            return ans(nums,0,k,0,sum/k);
        }
    }
};