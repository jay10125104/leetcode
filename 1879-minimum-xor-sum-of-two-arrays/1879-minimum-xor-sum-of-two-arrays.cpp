class Solution {
public:
    int dp[15][1<<15];
    int ans(vector<int>&nums1,vector<int>&nums2,int idx,int mask){
        if(idx==nums1.size()){
            return 0;
        }
        else if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        else{
            int sol=INT_MAX;
            for(int i=0;i<nums1.size();i++){
                if((mask&(1<<i))==0){
                    sol = min(sol,ans(nums1,nums2,idx+1,mask|(1<<i))+(nums1[idx]^nums2[i]));
                }
            }
            return dp[idx][mask] = sol;
        }
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return ans(nums1,nums2,0,0);
    }
};