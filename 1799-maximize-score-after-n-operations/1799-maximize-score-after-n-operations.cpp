class Solution {
public:
    int dp[1<<15][8];
    int ans(vector<int>&nums,int mask,int idx){
        int t = __builtin_popcount(mask);
        if(t==nums.size()){
            return 0;
        }
        else if(dp[mask][idx]!=-1){
            return dp[mask][idx];
        }
        else{
            int sol=0;
            for(int i=0;i<nums.size();i++){
                if((mask&(1<<i))==0){
                    int ti = mask|(1<<i);
                    for(int j=0;j<nums.size();j++){
                        if((ti&(1<<j))==0){
                            int tj = ti|(1<<j);
                            sol = max(sol,__gcd(nums[i],nums[j])*idx+ans(nums,tj,idx+1));
                        }
                    }
                }
            }
            return dp[mask][idx] = sol;
        }
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return ans(nums,0,1);
    }
};