class Solution {
public:
    int minCost(vector<vector<int>>& v) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        
        q.push({0,{0,0}});
        int m=v.size();
        int n=v[0].size();
        // long long int mp[m][n];
        vector<vector<int>>mp(m,vector<int>(n,INT_MAX));
        while(q.size()){
            auto it = q.top();
            q.pop();
            int i=it.second.first;
            int j=it.second.second;
            if(mp[i][j]<=it.first){
                continue;
            }
            mp[i][j] = it.first;
            if(i-1>=0){
                if(v[i][j]==4){
                    q.push({it.first,{i-1,j}});
                }
                else{
                    q.push({it.first+1,{i-1,j}});                    
                }
            }
            if(j-1>=0){
                if(v[i][j]==2){
                    q.push({it.first,{i,j-1}});
                }
                else{
                    q.push({it.first+1,{i,j-1}});                    
                }
            }
            if(i+1<m){
                if(v[i][j]==3){
                    q.push({it.first,{i+1,j}});
                }
                else{
                    q.push({it.first+1,{i+1,j}});                    
                }
            }
            if(j+1<n){
                if(v[i][j]==1){
                    q.push({it.first,{i,j+1}});
                }
                else{
                    q.push({it.first+1,{i,j+1}});                    
                }
            }
        }
        return mp[m-1][n-1];
    }
};