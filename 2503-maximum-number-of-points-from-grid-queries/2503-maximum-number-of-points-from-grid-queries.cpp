class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& qi) {
        map<int,int>ans;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<int>mid = qi;
        sort(mid.begin(),mid.end());
        int count=0;
         int visited[m][n];
            memset(visited,0,sizeof(visited));
            q.push({0,0});
            visited[0][0]=1;
        for(int i=0;i<mid.size();i++){
            int t = mid[i];
            if(ans.find(t)!=ans.end()){
                continue;
            }
            queue<pair<int,int>>q1;
           
            while(q.size()){
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                q.pop();
                if(grid[x][y]>=t){
                // cout<<x<<" "<<y<<" "<<t<<endl;
                    q1.push({x,y});
                }
                else{
                    if((x-1)>=0 && visited[x-1][y]==0){
                        q.push({x-1,y});
                        visited[x-1][y]=1;
                    }
                    if((x+1)<m && visited[x+1][y]==0){
                        q.push({x+1,y});
                        visited[x+1][y]=1;
                        
                    }
                    if((y-1)>=0 && visited[x][y-1]==0){
                        q.push({x,y-1});
                        visited[x][y-1]=1;
                    }
                    if((y+1)<n && visited[x][y+1]==0){
                        q.push({x,y+1});
                        visited[x][y+1]=1;
                    }
                    count++;
                }
            }
            q=q1;
            // cout<<count<<endl;
            ans[t]=count;
        }
        vector<int>sol;
        for(auto &i:qi){
            sol.push_back(ans[i]);
        }
        return sol;
    }
};