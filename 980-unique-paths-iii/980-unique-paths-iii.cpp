class Solution {
public:
    int dp[21][21][22];
    int visited[21][21];
    int ans(vector<vector<int>>&v,int i,int j,int x,int y,int t,int count,int m,int n){
        // cout<<i<<" "<<j<<" "<<count<<endl;
        if(i<0 || j<0 || i>=m|| j>=n || visited[i][j] || v[i][j]==-1){
            return 0;
        }
        if((i==x) && (j==y)){
            return count==t;
        }
        // else if(dp[i][j][count]!=-1){
        //     return dp[i][j][count];
        // }
        else{
            int sol=0;
            visited[i][j]=1;
            sol+=ans(v,i+1,j,x,y,t,count+1,m,n);
            sol+=ans(v,i-1,j,x,y,t,count+1,m,n);
            sol+=ans(v,i,j+1,x,y,t,count+1,m,n);
            sol+=ans(v,i,j-1,x,y,t,count+1,m,n);
            visited[i][j]=0;
            return dp[i][j][count] = sol;
        }
        
    }
    int uniquePathsIII(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        // int coun/t=0;
        int x=0;
        int y=0;
        int x1=0;
        int y1=0;
        memset(dp,-1,sizeof(dp));
        memset(visited,0,sizeof(visited));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    count++;
                }
                else if(v[i][j]==2){
                    x1=i;
                    y1=j;
                }
                else if(v[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        count++;
        // cout<<count<<endl;
        // cout<<x1<<" "<<y1<<endl;
        return ans(v,x,y,x1,y1,count,0,m,n);
    }
};