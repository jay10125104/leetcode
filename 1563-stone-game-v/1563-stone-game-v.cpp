class Solution {
public:
    int dp[501][501];
    int prefix[501];
    int stoneGameV(vector<int>& v) {
        memset(dp,0,sizeof(dp));
        memset(prefix,0,sizeof(prefix));
        prefix[0] = v[0];
        int n=v.size();
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+v[i];
        }
        // int n=v.size();
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j]=0;
                }
                else{
                    int back = ((i==0)?(0):prefix[i-1]);
                    int sum = prefix[j]-back;
                    int tillsum=0;
                    // cout<<sum<<" "<<i<<" "<<j<<endl;
                    for(int part=i;part<j;part++){
                        tillsum+=v[part];
                        if(tillsum>(sum-tillsum)){
                            dp[i][j] = max(dp[i][j],dp[part+1][j]+(sum-tillsum));
                        }
                        else if(tillsum<(sum-tillsum)){
                            dp[i][j] = max(dp[i][j],dp[i][part]+tillsum);
                        }
                        else{
                            dp[i][j] = max({dp[i][j],dp[i][part]+tillsum,dp[part+1][j]+(sum-tillsum)});
                        }
                        // dp[i][j] = max(dp[i][j],);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};