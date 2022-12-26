long long int powerexpo(long long int x,long long int y,long long int p){
    long long int res = 1;
    x = x % p; 
    if (x == 0)
        return 0;
    while (y > 0){
        if (y & 1){
            res = (res*x) % p;
        }y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
class Solution {
public:
    int countPartitions(vector<int>& v, int k) {
        long long int n=v.size();
        long long int dp[n+1][k];
        memset(dp,0,sizeof(dp));
        int mod = 1000000007;
        long long int sum=0;
        for(auto &i:v){
            sum+=i;
        }
        if((2*k)>sum){
            return 0;
        }
        dp[0][0]=1;
        long long int ans =0;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<k;j++){
                if(i==0){

                }
                else{
                    int x=v[i-1];
                    dp[i][j] = dp[i-1][j];
                    if((j-x)>=0){
                        dp[i][j] = (dp[i][j]%mod + dp[i-1][j-x]%mod)%mod;
                    }
                }
                if(i==n){
                    ans = (ans%mod + dp[i][j]%mod)%mod;
                }
            }
        }
        long long int total = 1;
        for(int i=0;i<n;i++){
            total = ((total%mod)*2 + mod)%mod;
        }
        long long int left = (total%mod - (2*ans)%mod)%mod;
        left = (left+mod)%mod;
        return (left+mod)%mod;
    }
};