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
            if(parent[node]==node){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        void Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u!=v)
            parent[v] = u;
        }
    };
    vector<bool> friendRequests(int n, vector<vector<int>>& v, vector<vector<int>>& q){
        vector<bool>ans;
            unionfind u = unionfind(n);
        for(auto &i:q){
            bool flag=true;
            int x = u.find(i[0]);
            int y = u.find(i[1]);
            for(auto &i:v){
                int p = u.find(i[0]);
                int q = u.find(i[1]);
                if((x==p&&y==q) || (x==q&&y==p)){
                    flag= false;
                    break;
                }
            }
            if(flag==true){
                u.Union(i[0],i[1]);
            }
            ans.push_back(flag);
        }
        return ans;
    }
};