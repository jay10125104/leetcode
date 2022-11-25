class Solution {
public:
    int dp[501][501];
    int ans(vector<int>&nums1,vector<int>&nums2,int idx,int start){
        if(idx>=nums1.size() || start>=nums2.size()){
            return 0;
        }
        else if(dp[idx][start]!=-1){
            return dp[idx][start];
        }
        else{
            int sol=0;
            int x = ans(nums1,nums2,idx+1,start);
            for(int i=start;i<nums2.size();i++){
                if(nums1[idx]==nums2[i]){
                    sol = max(sol,1+ans(nums1,nums2,idx+1,i+1));
                }
            }
            return dp[idx][start] = max(x,sol);
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>>dp = vector(501,vector<int);
        memset(dp,-1,sizeof(dp));
        int n=nums1.size();
        return ans(nums1,nums2,0,0);
    }
};