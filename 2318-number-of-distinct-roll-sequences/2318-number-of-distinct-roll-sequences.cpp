class Solution {
public:
    long long int dp[10001][8][8];
    int mod=1000000007;
    long long int ans(int idx,int n,int prev,int prevprev){
        if(idx==n){
            return 1;
        }
        else if(dp[idx][prev+1][prevprev+1]!=-1){
            return dp[idx][prev+1][prevprev+1];
        }
        else{
            long long int sol=0;
            for(int i=1;i<=6;i++){
                int consider = prev;
                if(consider==-1){
                    consider=1;
                }
                if(__gcd(consider,i)==1 && (prevprev!=i) && (i!=prev)){
                    sol = (sol%mod + ans(idx+1,n,i,prev)%mod)%mod; 
                }
            }
            return dp[idx][prev+1][prevprev+1]=sol;
        }
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return ans(0,n,-1,-1);
    }
};