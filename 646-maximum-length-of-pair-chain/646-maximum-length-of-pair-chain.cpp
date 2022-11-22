class Solution {
public:
    int dp[1001];
    int findLongestChain(vector<vector<int>>& p) {
        int ans=0;
        memset(dp,0,sizeof(dp));
        int n=p.size();
        dp[0]=1;
        sort(p.begin(),p.end());
        for(int i=1;i<n;i++){
            // cout<<p[i][0]<<" "<<p[i][1]<<endl;
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(p[j][1]<p[i][0]){
                    dp[i] = max(dp[i],dp[j]+1); 
                }
            }
            // cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        return max(ans,1);
    }
};