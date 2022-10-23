class Solution {
public:
    int minimumObstacles(vector<vector<int>>& v) {
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>visited(m,vector<int>(n,INT_MAX));
        // visited[0][0]=0;
        while(q.size()){
            auto it = q.top();
            q.pop();
            int i=it.second.first;
            int j = it.second.second;
            int x = it.first;
            if(i<0 || j<0 || i==m || j==n){
                continue;
            }
            if(v[i][j]){
                x++;
            }
            if(visited[i][j]<=x){
                continue;
            }
            
            visited[i][j] = x;
            if(i==m-1 && j==n-1){
                return x;
            }
            q.push({x,{i-1,j}});
            q.push({x,{i+1,j}});
            q.push({x,{i,j-1}});
            q.push({x,{i,j+1}});
        }
        return -1;
    }
};