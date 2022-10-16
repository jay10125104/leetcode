class Solution {
public:
    struct unionfind{
        vector<int>parent;
        vector<int>size;
      unionfind(int n){
          parent.resize(n);
          size.resize(n);
          for(int i=0;i<n;i++){
              parent[i]=i;
          }
          
      }
        int find(int node){
            if(parent[node] == node){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        void Union(int u,int v){
            u = find(u);
            v = find(v);
            parent[v] = u;
        }
        
    };
    int removeStones(vector<vector<int>>& v) {
        unionfind u = unionfind(v.size());
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i][0]==v[j][0] || v[i][1]==v[j][1]){
                    u.Union(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<u.parent.size();i++){
            if(u.parent[i]==i){
                ans++;
            }
        }
        return n-ans;
    }
};