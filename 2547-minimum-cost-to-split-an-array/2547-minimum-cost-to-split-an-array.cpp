class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int>dp(n,INT_MAX);
        dp[0]=k;
        for(int i=1;i<n;i++){
            unordered_map<int,int>m;
            m[nums[i]]++;
            long long int mid=0;
            for(int j=i-1;j>=0;j--){
                dp[i]=min(dp[i],k+mid+dp[j]);
                m[nums[j]]++;
                if(m[nums[j]]==2){
                    mid+=2;
                }
                else if(m[nums[j]]>1){
                    mid++;
                }
            }
            dp[i]=min(dp[i],k+mid);
        }
        return dp[n-1];
    }
};