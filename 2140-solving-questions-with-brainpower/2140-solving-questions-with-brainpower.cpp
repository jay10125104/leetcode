class Solution {
public:
    long long int ans(vector<vector<int>>&v,int idx,vector<long long int>&dp){
        if(idx>=v.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        long long pick = (long long)v[idx][0] + ans(v,idx+v[idx][1] +1,dp);
        long long nonpick = ans(v,idx+1,dp);
        
        return dp[idx] = max(pick,nonpick);
        
    }
    long long mostPoints(vector<vector<int>>& q) {
       
        vector<long long >dp(q.size(),-1);
        int k=0;
        return ans(q,k,dp);
    }
};