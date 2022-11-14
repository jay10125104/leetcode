class Solution {
public:
    int ans(vector<int>&v,int idx,int count){
        if(idx==v.size()){
            return 0;
        }
        else if(dp[idx][count]!=-1){
            return dp[idx][count];
        }
        int pick = count*v[idx] + ans(v,idx+1,count+1);
        int npick = ans(v,idx+1,count);
        return dp[idx][count] = max(pick,npick);
    }
    int dp[501][501];
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return ans(v,0,1);
    }
};