class Solution {
public:
    int mod = 1000000007;
    int dp[51][51][51];
    int ans(int m,int n,int i,int j,int k){
        if(i<0||j<0||i==m||j==n){
            return 1;
        }
        else if(k<=0){
            return 0;
        }
        else if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        else{
            long long int sol=0;
            sol+=(ans(m,n,i+1,j,k-1));
            sol+=(ans(m,n,i-1,j,k-1));
            sol+=(ans(m,n,i,j+1,k-1));
            sol+=(ans(m,n,i,j-1,k-1));
            return dp[i][j][k] = (mod+sol%mod)%mod;
        }
    }
    int findPaths(int m, int n, int k, int i, int j) {
        memset(dp,-1,sizeof(dp));
        return ans(m,n,i,j,k);
    }
};