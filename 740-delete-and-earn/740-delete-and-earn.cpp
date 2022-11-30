class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int v[20001];
        memset(v,0,sizeof(v));
        int dp[20001];
        memset(dp,0,sizeof(dp));
        for(auto &i:nums){
            v[i]+=i;
        }
        dp[0] = v[0];
        dp[1] = max(v[0],v[1]);
        for(int i=2;i<=20000;i++){
            dp[i]=max(dp[i-1],v[i]+dp[i-2]);
        }
        return dp[20000];
        
    }
};