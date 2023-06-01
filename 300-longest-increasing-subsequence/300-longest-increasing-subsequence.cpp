class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
    int ans=-1;
    vector<int>dp(n,0);
    for(int i=0;i<n;i++){
        int mx=0;
        for(int j=0;j<i;j++){
            if(v[i]>v[j]){
                mx=max(mx,dp[j]);
            }
        }
        dp[i] = mx+1;
        ans=max(ans,dp[i]);
    }
return ans;
    }
};