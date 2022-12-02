class Solution {
public:
    long long maxPoints(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        long long int dp[m][n];
        long long int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            vector<long long int>left(n);
            vector<long long int>right(n);
                if(i==0){
                for(int j=0;j<n;j++){
                    dp[i][j]=v[i][j];
                    if(i==m-1){
                            ans = max(ans,dp[i][j]);
                        }
                }
                    
                    
                }
                else{
                    left[0]=dp[i-1][0];
                    for(int j=1;j<n;j++){
                        left[j] = max(left[j-1]-1,dp[i-1][j]);
                    }
                    right[n-1]=dp[i-1][n-1];
                    for(int j=n-2;j>=0;j--){
                        right[j] = max(right[j+1]-1,dp[i-1][j]);
                    }
                    for(int k=0;k<n;k++){
                        dp[i][k]=max(left[k]+v[i][k],right[k]+v[i][k]);
                        if(i==m-1){
                            ans = max(ans,dp[i][k]);
                        }
                    }
                    
            }
            // cout<<endl;
        }
        return ans;
    }
};