class Solution {
public:
    int dp[100001];
    int ans(int n){
        if(n==0){
            return 0;
        }
        else if(dp[n]!=-1){
            return dp[n];
        }
        else{
            int sol = 1 - ans(n-1);
            for(int i=2;i<=sqrt(n);i++){
                sol = max(sol,1-ans(n-(i*i)));
            }
            return dp[n] = sol;
        }
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return ans(n)==1;
        // return 0;
        
    }
};