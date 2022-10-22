class Solution {
public:
    struct unionfind{
        vector<int>parent;
      unionfind(int n){
          parent.resize(n);
          for(int i=0;i<n;i++){
              parent[i]=i;
          }
      }  
        int find(int node){
            if(node==parent[node]){
                return parent[node];
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        bool Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u!=v){
                parent[u]=v;
                return false;
            }
            return true;
        }
    };
    vector<bool> areConnected(int n, int x, vector<vector<int>>& q) {
        unionfind u = unionfind(n+1);
        vector<int>visited(n+1);
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                for(int j=i;j<=n;j+=i){
                    if(__gcd(j,i)>x){
                        // cout<<i<<" "<<j<<endl;
                        visited[j] = 1;
                        u.Union(i,j);
                    }
                }
            }
        }
        vector<bool>ans;
        for(auto i:q){
            if(u.find(i[0])==u.find(i[1])){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};