class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& qi) {
        unordered_map<int,int>ans;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<int>mid = qi;
        sort(mid.begin(),mid.end());
        int count=0;
        queue<pair<int,int>>q1;
        int flag=0;
         int visited[m][n];
            memset(visited,0,sizeof(visited));
            q.push({0,0});
            visited[0][0]=1;
        for(int i=0;i<mid.size();i++){
            int t = mid[i];
            if(ans.find(t)!=ans.end()){
                continue;
            }
            if(flag==0){
           
            while(q.size()){
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                q.pop();
                if(grid[x][y]>=t){
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
                flag=1;
            }
            else{
                while(q1.size()){
                auto it = q1.front();
                int x = it.first;
                int y = it.second;
                q1.pop();
                if(grid[x][y]>=t){
                    q.push({x,y});
                }
                else{
                    if((x-1)>=0 && visited[x-1][y]==0){
                        q1.push({x-1,y});
                        visited[x-1][y]=1;
                    }
                    if((x+1)<m && visited[x+1][y]==0){
                        q1.push({x+1,y});
                        visited[x+1][y]=1;
                        
                    }
                    if((y-1)>=0 && visited[x][y-1]==0){
                        q1.push({x,y-1});
                        visited[x][y-1]=1;
                    }
                    if((y+1)<n && visited[x][y+1]==0){
                        q1.push({x,y+1});
                        visited[x][y+1]=1;
                    }
                    count++;
                }
            }
                flag=0;
            }
            
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