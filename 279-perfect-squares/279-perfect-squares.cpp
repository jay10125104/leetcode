class Solution {
public:
    int numSquares(int n) {
        vector<int>v;
        for(int i=1;i<=100;i++){
            v.push_back(i*i);
        }
        vector<long long int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(auto &j:v){
                if(i>=j)
                dp[i] = min(dp[i],dp[i-j]+1);
            }
        }
        return dp[n];
    }
};