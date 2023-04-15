class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& v, int k) {
        int n=v.size();
        int sol=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                int sum=0;
                int ans=INT_MIN;
                int sz=v[i-1].size();
                for(int part = 0;part<j && part<sz;part++){
                    sum+=v[i-1][part];
                    ans = max(ans,sum+dp[i-1][j-part-1]); //taking 1,2,3,...elements;
                }
                dp[i][j]=max(ans,dp[i-1][j]); //taking 0 element;
            }
        }
        return dp[n][k];
    }
};