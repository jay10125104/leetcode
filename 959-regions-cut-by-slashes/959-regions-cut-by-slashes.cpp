class Solution {
public:
    struct unionfind{
        vector<int>rank;
        vector<int>parent;
      unionfind(int n){
          vector<int>p(n);
          vector<int>r(n);
          for(int i=0;i<n;i++){
              p[i]=i;
          }
          rank = r;
          parent = p;
          
      }
        int find(int node){
            if(parent[node] ==node){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        bool unionthem(int u,int v){
            u = find(u);
            v = find(v);
            if(u==v){
                return true;
            }
            else{
                if(rank[u]==rank[v]){
                    parent[u]=v;
                    rank[v]++;
                }
                else if(rank[u]>rank[v]){
                    parent[v] = u;
                }
                else{
                    parent[u] = v;
                }
                return false;
                
            }
        }
    };
    int regionsBySlashes(vector<string>& s) {
        int ans=0;
        cout<<s[0];
        int n = s.size()+1;
        cout<<n<<endl;
        unionfind ui = unionfind(n*n);
        for(int i=1;i<n;i++){
            // cout<<i<<" "<<i-1<<endl;
            ui.unionthem(i-1,i);
        }
        for(int j=1;j<n;j++){
            // cout<<n*j<<" "<<(n*(j-1))<<endl; 
            ui.unionthem(n*j,(n*(j-1)));
        }
        for(int i=1;i<n;i++){
            int u = s.size()*(s.size()+1) + i;
            // cout<<u<<" "<<u-1<<endl;
            ui.unionthem(u,u-1);
        }
         for(int i=1;i<n;i++){
            int u = (i+1)*n - 1;
             // cout<<u<<" "<<u-n<<endl;
            ui.unionthem(u,u-n);
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s[i].size();j++){
                if(s[i][j]=='/'){
                    int u = i*n+j+1;
                    int v = (i+1)*n + j;
                    if(ui.unionthem(u,v)){
                        ans++;
                    }
                }
                else if(s[i][j]==' '){
                    
                }
               else{
                   int u = i*n+j;
                   int v = (i+1)*n+j+1;
                   if(ui.unionthem(u,v)){
                       ans++;
                   }
                   
               }
            }
        }
        return ans+1;
    }
};