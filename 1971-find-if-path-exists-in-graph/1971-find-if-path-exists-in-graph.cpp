
class Solution {
public:
    struct unionfind{
        vector<int>parent;
        vector<int>rank;
        unionfind(int n){
            vector<int>p(n);
            vector<int>r(n);
            for(int i=0;i<n;i++){
                p[i]=i;
            }
            parent = p;
            rank = r;
        }
        int find(int node){
            if(parent[node]==node){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        void unionthem(int u,int v){
            int x = find(u);
            int y = find(v);
            if(rank[x]==rank[y]){
                parent[x] = y;
                rank[y]++;
            }
            else if(rank[x]<rank[y]){
                parent[x] = y;
            }
            else{
                parent[y] = x;
            }
        }
    };
    bool validPath(int n, vector<vector<int>>& e, int source, int destination) {
        unionfind u = unionfind(n);
        for(auto i:e){
            u.unionthem(i[0],i[1]);
        }
        cout<<u.find(source)<<" ";
        return u.find(source)==u.find(destination);
    }
};