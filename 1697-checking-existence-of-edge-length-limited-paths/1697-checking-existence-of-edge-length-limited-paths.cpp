bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
class Solution {
public:
    struct unionfind{
        vector<int>parent;
        unionfind(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
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
                if(u!=v){
                        parent[u] = v;
                    }
            }      
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& v, vector<vector<int>>& q) {
        sort(v.begin(),v.end(),cmp);
        map<pair<int,int>,int>m;
        int count=0;
        for(int i=0;i<q.size();i++){
            q[i].push_back(i);
        }
        sort(q.begin(),q.end(),cmp);
        
        unionfind u = unionfind(n);
        vector<bool>ans(q.size(),false);
            int idx=0;
        for(int i=0;i<q.size();i++){
            int x = q[i][2];
            while(idx<v.size() && v[idx][2]<x){
                u.Union(v[idx][0],v[idx][1]);
                idx++;
            }
            if(u.find(q[i][0])==u.find(q[i][1])){
                ans[q[i][3]] = true;
            }
        }
        return ans;
    }
};