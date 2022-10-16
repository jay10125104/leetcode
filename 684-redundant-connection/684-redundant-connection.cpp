class Solution {
public:
    struct unionfind1{
        vector<int>parent;
        vector<int>rank;
        unionfind1(int n){
            parent.resize(n);
            rank.resize(n);
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
        bool unionthem(int u,int v){
            u = find(u);
            v = find(v);
            if(u==v){
                return true;
            }
            else{
                if(rank[u]<rank[v]){
                    parent[u] = v;
                }
                else if(rank[v]<rank[u]){
                    parent[v] = u;
                }
                else{
                    parent[v] = u;
                    rank[u]++;
                }
                return false;
            }
        }
        
    };
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        int n=v.size()+1;
        unionfind1 u = unionfind1(n);
        int ans1,ans2;
        for(auto i:v){
            if(u.unionthem(i[0],i[1])){
                ans1 = i[0];
                ans2 = i[1];
            }
        }
        return {ans1,ans2};
        
    }
};