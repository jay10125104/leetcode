class Solution {
public:
    struct unionfind{
        vector<int>parent;
        vector<int>size;
      unionfind(int n){
          size.resize(n);
          parent.resize(n);
          for(int i=0;i<n;i++){
              parent[i] = i;
          } 
          size[0]=1;
      }  
        int find(int node){
            if(node==parent[node]){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        void Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u!=v){
                if(size[u]>size[v]){
                    parent[v] = u;
                }
                else{
                    parent[u] = v;
                }
            }
        }
    };
    int latestDayToCross(int r, int c, vector<vector<int>>& v) {
        r++;
        c++;
        unionfind u = unionfind(r*c);
        map<int,int>m1;
        map<int,int>m2;
        for(int i=0;i<r*c;i+=c){
            u.Union(0,i);
            m1[i]++;
        }
        for(int i=c-1;i<r*c;i+=c){
            u.Union(c-1,i);
            m2[i]++;
        }
        // cout<<"fd";
        int ans=0;
        
        for(auto &i:v){
            int x = i[0]-1;
            int y = i[1]-1;
            int first=(x*c+y);
            int second = ((x+1)*(c) + (y+1));
            int third  = (x*c + (y+1));
            int forth = ((x+1)*c + (y));
            // cout<<first<<" "<<second<<" "<<third<<" "<<forth<<endl;
            u.Union(first,second);
            u.Union(forth,third);
            u.Union(first,first+1);
            u.Union(forth,forth+1);
            // cout<<u.find(r*c-1)<<endl;
             if(u.size[u.find(r*c-1)]){
                 break;
             }
            ans++;
        }
        return ans;
        
    }
};