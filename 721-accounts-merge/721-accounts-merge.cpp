class Solution {
public:
    struct unionfind{
    int n;
    vector<int>parent;
    unionfind(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
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
    void Union(int u,int v){
        u = find(u);
        v = find(v);
        parent[u] = v;
    }
};
    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        map<string,int>m;
        unionfind u = unionfind(v.size());
        for(int i=0;i<v.size();i++){
            for(int j=1;j<v[i].size();j++){
                if(m.find(v[i][j])==m.end()){
                    m[v[i][j]] = i;
                }
                else{
                    u.Union(m[v[i][j]],i);
                }
            }
        }
        map<int,vector<string>>ans;
        for(auto i:m){
            int x = u.find(i.second);
            if(ans.find(x)==ans.end()){
                ans[x].push_back(v[x][0]);
            }
            ans[x].push_back(i.first);
        }
        vector<vector<string>>sol;
        for(auto i:ans){
            sol.push_back(i.second);
        }
        return sol;
    }
};