class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        queue<pair<int,int>>q;
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!v[i][j]){
                q.push({i,j});
                    visited[i][j]=1;
                }
                
            }
        }
        int count=1;
        while(q.size()){
            int x = q.size();
            while(x--){
                auto it = q.front();
                int i = it.first;
                int j=it.second;
                q.pop();
                if(i!=0 && visited[i-1][j]==0){
                    v[i-1][j] = count;
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                if(j!=0 && visited[i][j-1]==0){
                    v[i][j-1] = count;
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
                if(i!=m-1 && visited[i+1][j]==0){
                    v[i+1][j] = count;
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
                if(j!=n-1 && visited[i][j+1]==0){
                    v[i][j+1] = count;
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
            }
            
            count++;
        }
        return v;
    }
};