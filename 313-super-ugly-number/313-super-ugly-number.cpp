class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& p) {
        long long int pointer[101];
        memset(pointer,0,sizeof(pointer));
        long long int dp[100001];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long int mn = INT_MAX;
            for(int j=0;j<p.size();j++){
                mn = min(mn,(long long int)((long long int)p[j]*(long long int)dp[pointer[j]]));
            }
            for(int j=0;j<p.size();j++){
                if((p[j]*dp[pointer[j]])==mn){
                    pointer[j]++;
                }
            }
            dp[i] = mn;
        }
        return dp[n-1];
    }
};