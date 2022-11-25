class Solution {
public:
    int dp[50000][2];
    int maxTurbulenceSize(vector<int>& arr) {
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        dp[0][0]=1;
        int ans=1;
        for(int i=1;i<arr.size();i++){
            // cout<<i<<" ";?
            if(arr[i]==arr[i-1]){
                dp[i][0]=1;
                dp[i][1]=1;
            }
            else if(arr[i]>arr[i-1]){
                dp[i][0] = dp[i-1][1]+1;
                dp[i][1] = 1;
            }
            else{
                dp[i][1] = dp[i-1][0]+1;
                dp[i][0]=1;
            }
            ans = max(ans,dp[i][0]);
            ans = max(ans,dp[i][1]);
            // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        return ans;
    }
};