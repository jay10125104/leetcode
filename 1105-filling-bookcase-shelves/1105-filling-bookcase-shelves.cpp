class Solution {
public:
    int dp[1001];
    int minHeightShelves(vector<vector<int>>& v, int k) {
        memset(dp,INT_MAX,sizeof(dp));
        dp[0] = v[0][1];
        int n=v.size();
        for(int i=1;i<n;i++){
            int mx = v[i][1];
            int sum = v[i][0];
            dp[i] = v[i][1] + dp[i-1];
            for(int j=i-1;j>=0;j--){
                sum+=v[j][0];
                if(sum<=k){
                    int t = (((j-1)>=0)?(dp[j-1]):(0));
                    mx = max(mx,v[j][1]);
                    dp[i] = min(dp[i],mx+t);
                }
                else{
                    break;
                }
            }
        }
        return dp[n-1];
    }
};