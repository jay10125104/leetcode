class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        queue<pair<int,int>>q;
        int count=0;
        int m=v.size();
        int n=v[0].size();
       vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){
                    count++;
                }
                else if(v[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int ans=0;
        while(q.size() && count){
            ans++;
            int x = q.size();
            while(x--){
                auto it = q.front();
                int i = it.first;
                q.pop();
                int j = it.second;
                if(i-1>=0 && visited[i-1][j]==0 && v[i-1][j]==1){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                    count--;
                }
                if(j-1>=0 && visited[i][j-1]==0 && v[i][j-1]==1){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                    count--;
                }
                if(i+1<m && visited[i+1][j]==0 && v[i+1][j]==1){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                    count--;
                }
                if(j+1<n && visited[i][j+1]==0 && v[i][j+1]==1){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                    count--;
                }
            }
        }
        if(count==0){
            return ans;
        }
        else{
            return -1;
        }
    }
};