class Solution {
public:
    int minimumTime(vector<vector<int>>& v) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        if(v[0][1]>1 && v[1][0]>1){
            return -1;
        }
        q.push({0,{0,0}});
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        while(q.size()){
            auto it = q.top();
            q.pop();
            int i=it.second.first;
            int j=it.second.second;
            int time = it.first;
            visited[i][j]=1;
            if(i==m-1 && j==n-1){
                return time;
            }
            if((i-1)>=0 && visited[i-1][j]==0){
                int diff = v[i-1][j]-time;
                if(diff<=1)
                q.push({time+1,{i-1,j}});
                else{
                    if(diff%2){
                        q.push({v[i-1][j],{i-1,j}});
                    }
                    else{
                        q.push({v[i-1][j]+1,{i-1,j}});                        
                    }
                }
                visited[i-1][j]=1;
                
            }
            if((i+1)<m && visited[i+1][j]==0){
                int diff = v[i+1][j]-time;
                if(diff<=1)
                q.push({time+1,{i+1,j}});
                else{
                    if(diff%2){
                        q.push({v[i+1][j],{i+1,j}});
                    }
                    else{
                        q.push({v[i+1][j]+1,{i+1,j}});                        
                    }
                }
                visited[i+1][j]=1;
                
            }
            if((j-1)>=0 && visited[i][j-1]==0){
                int diff = v[i][j-1]-time;
                if(diff<=1)
                q.push({time+1,{i,j-1}});
                else{
                    if(diff%2){
                        q.push({v[i][j-1],{i,j-1}});
                    }
                    else{
                        q.push({v[i][j-1]+1,{i,j-1}});                        
                    }
                }
                visited[i][j-1]=1;
            }
            if((j+1)<n && visited[i][j+1]==0){
               int diff = v[i][j+1]-time;
                if(diff<=1)
                q.push({time+1,{i,j+1}});
                else{
                    if(diff%2){
                        q.push({v[i][j+1],{i,j+1}});
                    }
                    else{
                        q.push({v[i][j+1]+1,{i,j+1}});                        
                    }
                }
                visited[i][j+1]=1;
                
            }
            
            
        }
        return -1;
    }
};