class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
         vector<pair<int,int>>v;
        int n=scores.size();
        for(int i=0;i<n;i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int dp[1001];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i]=v[i].second;
            for(int j=i-1;j>=0;j--){
                if(v[j].second<=v[i].second){
                    dp[i]=max(dp[i],dp[j]+v[i].second);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};