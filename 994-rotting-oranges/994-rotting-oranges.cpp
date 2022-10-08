class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int count = 0;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(v.size(),vector<int>(v[0].size()));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                else if(v[i][j]){
                    count++;
                }
            }
        }
        int ans=0;
        while(q.size() && count){
            int x = q.size();
            ans++;
            while(x--){
                auto it = q.front();
                int  i = it.first;
                int j=it.second;
                q.pop();
                if(i-1>=0 && v[i-1][j] && visited[i-1][j]==0){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                    count--;
                }
                if(i+1<v.size() && v[i+1][j] && visited[i+1][j]==0){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                    count--;
                }
                if(j-1>=0 && v[i][j-1] && visited[i][j-1]==0){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                    count--;
                }
                if(j+1<v[0].size() && v[i][j+1] && visited[i][j+1]==0){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                    count--;
                }
            }
        }
        if(!count){
            return ans;
        }
        return -1;
    }
};