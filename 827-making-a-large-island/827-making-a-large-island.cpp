class Solution {
public:
    struct unionfind{
        vector<int>parent;
        vector<int>size;
      unionfind(int n){
          size.resize(n);
          parent.resize(n);
          for(int i=0;i<n;i++){
              parent[i]=i;
              size[i]=1;
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
        int Union(int u,int v){
            u = find(u);
            v= find(v);
            if(u!=v){
                size[u]+=size[v];
                parent[v] = u;
            }
            return size[u];
        }
    };
    int largestIsland(vector<vector<int>>& v) {
        int n=v.size();
        unionfind u = unionfind(n*n);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                int node = i*n + j;
                if(i-1>=0 && v[i-1][j]){
                    int newnode = (i-1)*(n) + j;
                    u.Union(node,newnode);
                    // ans = max(u.size[u.find(node)]);
                }
                    if(j-1>=0 && v[i][j-1]){
                    
                   u.Union(node,node-1);
                    // ans = max(u.size[u.find(node)]);
                }
                    ans = max(ans,u.size[u.find(node)]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    int count=1;
                    set<int>s;
                    int id = i*n+j;
                    if(i-1>=0 && v[i-1][j]){
                        int newid = id - n;
                        int x = u.find(newid);
                        if(!s.count(x)){
                            s.insert(x);
                            count+=u.size[x];
                        }
                    }
                    if(j-1>=0 && v[i][j-1]){
                        int newid = id - 1;
                        int x = u.find(newid);
                        if(!s.count(x)){
                            s.insert(x);
                            count+=u.size[x];
                        }
                    }
                    if(i+1<n && v[i+1][j]){
                        int newid = id + n;
                        int x = u.find(newid);
                        if(!s.count(x)){
                            s.insert(x);
                            count+=u.size[x];
                        }
                    }
                    if(j+1<n && v[i][j+1]){
                        int newid = id + 1 ;
                        int x = u.find(newid);
                        if(!s.count(x)){
                            s.insert(x);
                            count+=u.size[x];
                        }
                    }
                    ans = max(ans,count);
                    
                }
            }
        }
        return ans;
    }
};