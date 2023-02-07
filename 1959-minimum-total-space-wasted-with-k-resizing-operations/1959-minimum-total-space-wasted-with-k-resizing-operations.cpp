class Solution {
public:
    long long int dp[201][201];
    long long int ans(vector<int>&nums,int i,int k){
        
        if(i==nums.size()){
            return 0;
        }
        if(k==-1){
            return INT_MAX;
        }
        else if(dp[i][k]!=-1){
            return dp[i][k];
        }
        else{
            int mx=0;
            long long int sum=0;
            long long int mn=INT_MAX;
            for(int j=i;j<nums.size();j++){
                mx = max(mx,nums[j]);
                sum+=nums[j];
                mn=min(mn,mx*(j-i+1)-sum+ans(nums,j+1,k-1));
            }
            return  dp[i][k] = mn;
        }
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return ans(nums,0,k);
    }
};