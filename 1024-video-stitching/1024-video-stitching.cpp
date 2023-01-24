class Solution {
public:
    int videoStitching(vector<vector<int>>& v, int t){
        sort(v.begin(),v.end());
        vector<long long int>dp(v.size(),INT_MAX);
        long long int ans = INT_MAX;
        for(int i=0;i<v.size();i++){
            if(v[i][0]==0){
                dp[i]=1;
            }
            for(int j=i-1;j>=0;j--){
                if(v[i][0]>=v[j][0] && v[i][0]<=v[j][1]){
                    dp[i]=min(dp[i],dp[j]+1);
                }
                
            }
            if(v[i][1]>=t){
                ans = min(ans,dp[i]);
            }
            // cout<<dp[i]<<" "<<v[i][0]<<" "<<v[i][1]<<" "<<ans<<endl;
        }
        return ((ans)!=INT_MAX)?(ans):(-1);
    }
};