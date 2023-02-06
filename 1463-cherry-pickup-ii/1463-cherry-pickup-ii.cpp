class Solution {
public:
    int dp[70][70][70][70];
    long long int ans(vector<vector<int>>&v,int i,int j,int a,int b){
        if(i<0 || j<0 || a<0 || b<0 || i>=v.size() || a>=v.size() || j>=v[0].size() || b>=v[0].size()){
            return 0;
        }
        if(i==(v.size()-1)){
            if(i==a && j==b){
           return v[i][j] ;
            }
       else{
           return v[i][j] + v[a][b] ;
            }
        }
        if(dp[i][j][a][b]!=-1){
            return dp[i][j][a][b];
        }
        vector<int>dir= {-1,0,1};
        long long int mx=0;
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                mx = max(mx,ans(v,i+1,j+dir[p],a+1,b+dir[q]));
            }
        }
       if(i==a && j==b){
           return dp[i][j][a][b] = v[i][j] + mx;
       }
       else{
           return dp[i][j][a][b]=v[i][j] + v[a][b] + mx;
       }
    
    }
    int cherryPickup(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        return ans(v,0,0,0,v[0].size()-1);
    
    }
};