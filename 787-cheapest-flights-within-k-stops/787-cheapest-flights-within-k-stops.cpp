class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        k++;
        vector<pair<int,int>>adj[n];
        for(auto i:v){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>visited(n,INT_MAX);
        while(q.size()&&k){
            k--;
            int x = q.size();
            // cout<<x<<" ";
            while(x--){
                auto it = q.front();
                q.pop();
                for(auto i:adj[it.first]){
                    // cout<<i.second+it.second<<" "<<visited[i.first]<<endl;
                    if(i.second+it.second<visited[i.first]){
                        q.push({i.first,i.second+it.second});
                        visited[i.first] = i.second+it.second;
                    }
                }
            }
        }
        return (visited[dst]!=(INT_MAX)?(visited[dst]):(-1));
    }
};