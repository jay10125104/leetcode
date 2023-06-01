class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        if(v[0][0]){
            return -1;
        }
        else{
            queue<vector<int>>q;
            int m=v.size();
            int n=v[0].size();
            q.push({0,0,1});
            int dp[m][n];
            memset(dp,0,sizeof(dp));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]=INT_MAX;
                }
            }
            dp[0][0]=1;
            vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,-1},{1,1},{-1,1}};
            while(q.size()){
                auto it=q.front();
                int x = it[0];
                int y=it[1];
                int w = it[2];
                q.pop();
                for(auto &i:dir){
                    x+=i[0];
                    y+=i[1];
                    if(x>=0 && y>=0 && x<m && y<n && v[x][y]==0 && (dp[x][y]>(w+1))){
                        q.push({x,y,w+1});
                        // cout<<x<<" "<<y<<" "<<w+1<<endl;
                        dp[x][y]=w+1;
                    }
                    x-=i[0];
                    y-=i[1];
                }
            }
            return dp[m-1][n-1]==INT_MAX?(-1):(dp[m-1][n-1]);
            
        }
    }
};