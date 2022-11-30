class Solution {
public:
    int countHousePlacements(int n) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(4,0));
         if(n==1){
            return 4;
        }
        dp[1][0]=1;
        dp[1][1]=1;
        dp[1][2]=1;
        dp[1][3]=1;
        int sum=1000000007;
        
       
        for(int i=2;i<=n;i++){
            dp[i][0]=(dp[i-1][0]%sum+dp[i-1][1]%sum+dp[i-1][2]%sum+dp[i-1][3]%sum)%sum;
            dp[i][1]=(dp[i-1][0]%sum+dp[i-1][2]%sum);
            dp[i][2]=(dp[i-1][1]%sum+dp[i-1][0]%sum);
            dp[i][3] = dp[i-1][0]%sum;
        }
    return (dp[n][0]%sum + dp[n][1]%sum + dp[n][2]%sum + dp[n][3]%sum)%sum;
    }
};