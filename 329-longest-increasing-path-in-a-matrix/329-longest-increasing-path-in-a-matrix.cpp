class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
       vector<vector<int>>indegree(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0 && v[i-1][j]>v[i][j]){
                    indegree[i-1][j]++;
                }
                if(i+1<m && v[i+1][j]>v[i][j]){
                    indegree[i+1][j]++;
                }
                if(j-1>=0 && v[i][j-1]>v[i][j]){
                    indegree[i][j-1]++;
                }
                if(j+1<n && v[i][j+1]>v[i][j]){
                    indegree[i][j+1]++;
                }
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(indegree[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(q.size()){
            ans++;
            int x = q.size();
            while(x--){
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                if(i-1>=0 && v[i-1][j]>v[i][j]){
                    indegree[i-1][j]--;
                    if(indegree[i-1][j]==0){
                        q.push({i-1,j});
                    }
                }
                if(i+1<m && v[i+1][j]>v[i][j]){
                    indegree[i+1][j]--;
                    if(indegree[i+1][j]==0){
                        q.push({i+1,j});
                    }
                }
                if(j-1>=0 && v[i][j-1]>v[i][j]){
                    indegree[i][j-1]--;
                    if(indegree[i][j-1]==0){
                        q.push({i,j-1});
                    }
                }
                if(j+1<n && v[i][j+1]>v[i][j]){
                    indegree[i][j+1]--;
                    if(indegree[i][j+1]==0){
                        q.push({i,j+1});
                    }
                }
            }
        }
        return ans;
    }
};