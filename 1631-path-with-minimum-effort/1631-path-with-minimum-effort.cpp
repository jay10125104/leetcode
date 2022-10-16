class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        map<pair<int,int>,int>m;
        int x = v.size();
        int y = v[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        // m[{0,0}]=1;
        int ans=INT_MAX;
        while(q.size()){
            auto it = q.top();
            q.pop();
            int i = it.second.first;
            int j = it.second.second;
            if(m[{i,j}]){
                continue;
            }
            m[{i,j}]=1;
            // cout<<i<<" "<<j<<" "<<it.first<<" "<<endl;
            if(i==x-1 && j==y-1){
                return it.first;
            }
            else{
            if(i+1<x && m[{i+1,j}]==0){
                
                q.push({max(it.first,abs(v[i+1][j]-v[i][j])),{i+1,j}});
            }
            if(j+1<y && m[{i,j+1}]==0){
                
                q.push({max(it.first,abs(v[i][j+1]-v[i][j])),{i,j+1}});
            }
            if(i-1>=0 && m[{i-1,j}]==0){
                
                q.push({max(it.first,abs(v[i-1][j]-v[i][j])),{i-1,j}});
            }
            if(j-1>=0 && m[{i,j-1}]==0){
                
                q.push({max(it.first,abs(v[i][j-1]-v[i][j])),{i,j-1}});
            }
            }
            
            
        }
        return ans;
    }
};