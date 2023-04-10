class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& v){
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=1;
        priority_queue<pair<int,pair<int,int>>>q;
        q.push({-1,{0,0}});
        while(q.size()){
            // cout<<"df";
            int steps = (-1)*q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            int val=v[x][y];
            q.pop();
            if(x==m-1 && y==n-1){
                break;
            }
            // cout<<x<<" "<<y<<endl;
            for(int i=1;i<=val && (x+i)<m;i++){
                if(dp[x+i][y]>(steps+1)){
                    dp[x+i][y]=steps+1;
                    q.push({-1*(steps+1),{x+i,y}});
                }
            }
            for(int i=1;i<=val && (y+i)<n;i++){
                if(dp[x][y+i]>(steps+1)){
                    dp[x][y+i]=steps+1;
                    q.push({-1*(steps+1),{x,y+i}});
                }
            }
            
        }
        if(dp[m-1][n-1]==INT_MAX){
            return -1;
        }
        else{
            return dp[m-1][n-1];
        }
        
    }
};