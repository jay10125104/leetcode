class Solution {
public:
vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S,vector<int>time){
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      q.push({0,S});
      vector<int>distance(V,INT_MAX);
      vector<int>visited(V);
      while(q.size()){
          auto x = q.top();
          q.pop();
          int srcw = x.first;
          int srcidx = x.second;
          if(visited[srcidx]==1){
              continue;
          }
          else{
              if(srcw>=time[srcidx]){
                  continue;
              }
              distance[srcidx] = srcw;
              visited[srcidx]=1;
              for(auto i:adj[srcidx]){
                  if(visited[i.second]==0){
                      q.push({srcw+i.first,i.second});
                  }
              }
          }
      }
      return distance;
}
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back({it[2],it[1]});
            adj[it[1]].push_back({it[2],it[0]});
        }
        vector<int>ans = dijkstra(n,adj,0,disappear);
        for(auto &i:ans){
            if(i==INT_MAX){
                i=-1;
            }
        }
        return ans;
    }
};