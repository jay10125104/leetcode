class Solution {
public:
    struct unionfind{
        vector<int>parent;
      unionfind(int n){
          parent.resize(n);
          for(int i=0;i<n;i++){
              parent[i] = i;
          }
      }
        int find(int node){
            if(node==parent[node]){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        bool Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u==v){
                return false;
            }
            else{
                parent[u] = v;
                return true;
            }
        }
    };
    int minCostConnectPoints(vector<vector<int>>& p) {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                int distance = abs(p[i][0]-p[j][0])+abs(p[i][1] - p[j][1]);
                v.push_back({distance,{i,j}});
            }
        }
        unionfind u = unionfind(p.size());
        sort(v.begin(),v.end());
        // cout<<"df";
        int ans=0;
        for(auto i:v){
            int x = i.second.first;
            int y = i.second.second;
            // cout<<x<<" "<<y<<" ";
            // cout<<i.first<<endl;
            if(u.Union(x,y)){
                ans+=i.first;
            }
            
        }
        return ans;
    }
};