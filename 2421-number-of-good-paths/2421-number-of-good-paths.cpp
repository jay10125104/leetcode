class Solution {
public:
    struct unionfind{
        vector<int>parent;
      unionfind(int n){
          parent.resize(n);
          for(int i=0;i<n;i++){
              parent[i]= i;
          }
          
      }
        int find(int node){
            if(parent[node]==node){
                return parent[node];
            }
            else{
                return  parent[node]  =find(parent[node]);
            }
        }
        void Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u!=v){
            parent[u] = v;
            }
        }
    };
    int numberOfGoodPaths(vector<int>& v, vector<vector<int>>& e) {
        vector<int>adj[v.size()];
        map<int,vector<int>>m;
        for(auto i:e){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<v.size();i++){
            m[v[i]].push_back(i);
        }
        int ans=0;
        unionfind u = unionfind(v.size());
        vector<int>active(v.size());
        for(auto it:m){
            int x = it.first;
            for(auto &j:it.second){
                active[j]=1;
            for(auto i:adj[j]){
                if(active[i]==1){
                    // cout<<it.first<<" "<<
                    u.Union(i,j);
                }
            }
            }
            map<int,int>m1;
            for(auto &j:it.second){
                m1[u.find(j)]++;
            }
            for(auto &i:m1){
                ans+=((i.second)*(i.second-1))/2;
            }
        }
        cout<<ans<<endl;
        return v.size()+ans;
    }
};