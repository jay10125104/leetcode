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
                for(int p = i-k;p<=i+k;p++){
                    for(int q = j-k;q<=j+k;q++){
                        if(p>=0 && p<m && q>=0 && q<n){
                            sum+=v[p][q];
                        }
                    }
                }
                dp[i][j] = sum;
            }
        }
        return dp;
    }
};