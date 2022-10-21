class Solution {
public:
    int shortestPath(vector<vector<int>>& v, int k) {
        int m=v.size();
        int n=v[0].size();
        int dp[m][n][k+1];
        memset(dp,0,sizeof(dp));
        queue<vector<int>>q;
        q.push({0,0,0,k});
        vector<int>x = {0,1,0,-1};
        vector<int>y = {-1,0,1,0};
        dp[0][0][k]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            // dp[it[0]][it[1]][it[3]]=1;
            if(it[0]==m-1 && it[1]==n-1){
                return it[2];
            }
            for(int i=0;i<4;i++){
                int newx = it[0]+x[i];
                int newy = it[1]+y[i];
                if(newx>=0 && newy>=0 && newx<m && newy<n ){
                    if(v[newx][newy] && it[3] &&  dp[newx][newy][it[3]-1]==0){
                        q.push({newx,newy,it[2]+1,it[3]-1});
                        dp[newx][newy][it[3]-1]=1;
                        if(newx==m-1 && newy==n-1){
                            return it[2]+1;
                        }
                    }
                    else if(v[newx][newy]==0 && dp[newx][newy][it[3]]==0){
                        q.push({newx,newy,it[2]+1,it[3]});
                        dp[newx][newy][it[3]]=1;
                        if(newx==m-1 && newy==n-1){
                            return it[2]+1;
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};