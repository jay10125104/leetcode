class Solution {
public:
    double champagneTower(int p, int query_row, int query_glass) {
        double dp[101][101];
        memset(dp,0,sizeof(dp));
        dp[0][0] = p;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                double x = (double)dp[i][j];
                x--;
                if(x>=0){
                    dp[i][j]=1;
                    double left = (x)/2.0;
                    dp[i+1][j]+=left;
                    dp[i+1][j+1]+=left;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[query_row][query_glass];
    }
};