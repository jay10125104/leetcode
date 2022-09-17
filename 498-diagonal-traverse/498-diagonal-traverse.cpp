class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        int mt=v.size();
        int n=v[0].size();
        vector<vector<int>>visited(v.size(),vector<int>(v[0].size(),0));
        stack<pair<int,int>>s;
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        vector<vector<int>>ans;
        vector<int>mid;
        int count=0;
        while(q.size()){
            int x = q.size();
            vector<int>m;
            while(x--){
                auto i = q.front();
                q.pop();
                m.push_back(v[i.first][i.second]);
                if((i.second+1)<n && visited[i.first][i.second+1]==0){
                    q.push({i.first,i.second+1});
                    visited[i.first][i.second+1]=1;
                }
                if(((i.first+1)<mt) && visited[i.first+1][i.second]==0){
                    q.push({i.first+1,i.second});
                    visited[i.first+1][i.second]=1;
                }
            }
            if(count%2==0){
                reverse(m.begin(),m.end());
            }
            for(auto i:m){
                mid.push_back(i);
            }
            count++;
            
        }
        return mid;
    }
};