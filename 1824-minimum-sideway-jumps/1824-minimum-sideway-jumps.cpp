class Solution {
public:
    int dp[500001][3];
    int ans(vector<vector<int>>&t,int idx,int col,vector<vector<int>>&visited){
        if(col<0 || col>=3 || t[idx][col]){
            return 1000;
        }
        if(dp[idx][col]!=-1){
            return dp[idx][col];
        }
        else if(idx==t.size()-1){
            return 0;
        }
        else{
            return dp[idx][col] = min({1+ans(t,idx+1,col+1,visited),1+ans(t,idx+1,col-1,visited),ans(t,idx+1,col,visited)});
        }
    }
    int minSideJumps(vector<int>& v) {
        int n=v.size();
        int dp[n][3];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        dp[0][1]=0;
        dp[0][2]=1;
        for(int i=1;i<v.size();i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            if(v[i])
            dp[i][v[i]-1]=1000000;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j!=k){
                        dp[i][j]=min(dp[i][j],dp[i][k]+1);
                    }
                }
            }
            if(v[i])
            dp[i][v[i]-1]=1000000;
            // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
};