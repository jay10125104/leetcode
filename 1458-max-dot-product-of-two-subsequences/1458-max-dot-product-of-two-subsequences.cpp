class Solution {
public:
    int dp[501][501];
    long long solve(vector<int>&nums1, vector<int>&nums2,int i,int j,int n,int m)
    {
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=max(solve(nums1,nums2,i+1,j,n,m),max(solve(nums1,nums2,i,j+1,n,m),(nums1[i]*nums2[j])+solve(nums1,nums2,i+1,j+1,n,m)));
    }
    long long maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums1,nums2,0,0,nums1.size(),nums2.size()),n=nums1.size(),m=nums2.size();
		//id your answer is 0 that means your max dot product is negative
        if(ans!=0)return ans;
		//then do maximum of(min from num1 and max from nums2 ) , f(max from num1 and min from nums2 )
        int mini=*min_element(nums1.begin(),nums1.end()),maxi=*max_element(nums2.begin(),nums2.end());
        ans=mini*maxi;
		mini=*min_element(nums2.begin(),nums2.end()),maxi=*max_element(nums1.begin(),nums1.end());
        ans=max(ans,mini*maxi);
        return ans;
    }
};