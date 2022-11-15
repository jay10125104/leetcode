class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& v, int k) {
        int m=v.size();
        int n = v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        // memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                // cout<<max(0,i-k)<<" "<<min(i+k,m)<<endl;
                for(int p = max(0,i-k);p<=min(i+k,m-1);p++){
                    for(int q = max(0,j-k);q<=min(j+k,n-1);q++){
                            sum+=v[p][q];
                    }
                }
                // cout<<"df";
                dp[i][j] = sum;
            }
        }
        return dp;
    }
};