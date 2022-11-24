class Solution {
public:
    int lastStoneWeightII(vector<int>& v) {
        int n=v.size();
        int sum=0;
        for(auto &i:v){
            sum+=i;
        }
        int sum1=sum;
        sum = sum/2;
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                int x = v[i-1];
                if(j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    if((j-x)>=0){
                        dp[i][j] = dp[i][j]|dp[i-1][j-x];
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=sum;i++){
            if(dp[n][i]){
            int x = sum1-i;
            ans=min(ans,abs(x-i));
                }
        }
        return ans;
    }
};