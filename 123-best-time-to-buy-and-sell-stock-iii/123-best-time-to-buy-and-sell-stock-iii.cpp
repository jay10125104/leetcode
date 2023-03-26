class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<int>dp1(n);
        int mn=v[0];
        dp1[0]=0;
        for(int i=1;i<n;i++){
            dp1[i]=dp1[i-1];
            mn = min(mn,v[i]);
            dp1[i] = max(dp1[i],v[i]-mn);
        }
        vector<int>dp2(n);
        int mx=v[n-1];
        dp1[n-1]=0;
        
        for(int i=n-2;i>=0;i--){
            dp2[i] = dp2[i+1];
            mx = max(mx,v[i]);
            dp2[i] = max(dp2[i],mx-v[i]);
            // ans = max(ans,dp1[i]+dp2[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp1[i]+dp2[i]);
        }
        return ans;
        
        
    }
};