class Solution {
public:
    int is_valid(int a,int b,int m,int n){
        if(a<0 || b<0 || a==m || b==n){
            return 0;
        }
        else{
            return 1;
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        queue<pair<int,int>>q;
        int visited[m][n];
        int dp[m][n];
        memset(visited,0,sizeof(visited));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int level=0;
        while(q.size()){
            int x=q.size();
            while(x--){
                auto it=q.front();
                q.pop();
                int a=it.first;
                int b=it.second;
                dp[a][b]=level;
                if(is_valid(a-1,b,m,n) && visited[a-1][b]==0){
                    q.push({a-1,b});
                    visited[a-1][b]=1;
                }
                if(is_valid(a+1,b,m,n) && visited[a+1][b]==0){
                    q.push({a+1,b});
                    visited[a+1][b]=1;
                }
                if(is_valid(a,b-1,m,n) && visited[a][b-1]==0){
                    q.push({a,b-1});
                    visited[a][b-1]=1;
                }
                if(is_valid(a,b+1,m,n) && visited[a][b+1]==0){
                    q.push({a,b+1});
                    visited[a][b+1]=1;
                }
                
            }
            level++;
        }
        int dis[m][n];
        memset(dis,-1,sizeof(dis));
        priority_queue<vector<int>>qi;
        vector<vector<int>>dir= {{0,1},{0,-1},{1,0},{-1,0}};
        qi.push({dp[0][0],0,0});
        dis[0][0]=dp[0][0];
        while(qi.size()){
            auto it = qi.top();
            qi.pop();
            int x=it[1];
            int y=it[2];
            if(x==m-1 && y==(n-1)){
                return it[0];
            }
            cout<<x<<" "<<y<<endl;  
            for(auto &i:dir){
                int newx=i[0]+x;
                int newy=i[1]+y;
                if(is_valid(newx,newy,m,n)==0){
                    continue;
                }
                int val = min(dp[newx][newy],it[0]);
                if( dis[newx][newy]<val){
                    dis[newx][newy]=val;
                    qi.push({val,newx,newy});
                }
            }
            
        }
        return -1;  
        
    }
};