class Solution {
public:
    int dp[501][501][2];
    int ans(vector<int>&nums1,vector<int>&nums2,int idx1,int idx2,int cnt1){
        if((idx1==nums1.size() || nums2.size()==idx2) && (cnt1==0)){
            return INT_MIN;
        }
        else if(idx1==nums1.size() || nums2.size()==idx2){
            return 0;
        }
        else if(dp[idx1][idx2][cnt1] !=-1 ){
            return dp[idx1][idx2][cnt1];
        }
        else{
            return dp[idx1][idx2][cnt1] = max({nums1[idx1]*nums2[idx2] + ans(nums1,nums2,idx1+1,idx2+1,1),ans(nums1,nums2,idx1+1,idx2,cnt1),ans(nums1,nums2,idx1,idx2+1,cnt1)});
        }
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return ans(nums1,nums2,0,0,0);
    }
};