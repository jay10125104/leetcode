class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int>dp(n,INT_MAX);
        dp[0]=k;
        unordered_map<int,int>m;
        
        for(int i=1;i<n;i++){
            m.clear();
            m[nums[i]]++;
            long long int mid=0;
            for(int j=i-1;j>=0;j--){
                dp[i]=min(dp[i],k+mid+dp[j]);
                int x = ++m[nums[j]];
                if(x==2){
                    mid+=2;
                }
                else if(x>1){
                    mid++;
                }
            }
            dp[i]=min(dp[i],k+mid);
        }
        return dp[n-1];
    }
};