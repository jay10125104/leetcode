class Solution {
public:
    int dp[50001][2];
    int ans(vector<int>&v,int buy,int fee,int idx){
        if(idx==v.size()){
            return 0;
        }
        else if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        else if(buy){
            return dp[idx][buy] = max(ans(v,buy,fee,idx+1),-v[idx] + ans(v,!buy,fee,idx+1));
        }
        else{
            return dp[idx][buy] = max(ans(v,buy,fee,idx+1),+v[idx]  - fee + ans(v,!buy,fee,idx+1));
        }
    }
    int maxProfit(vector<int>& v, int fee) {
        memset(dp,0,sizeof(dp));
        //1->buy;
        int n=v.size();
        dp[0][1] = -v[0];
        for(int i=1;i<n;i++){
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-v[i]);
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+v[i]-fee);
        }
        return dp[v.size()-1][0];
    }
};