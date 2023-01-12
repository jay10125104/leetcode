class Solution {
public:
vector<int>ans;
    vector<int> dfs(vector<int>adj[],vector<int>&visited,int src,string &s){
        visited[src]=1;
        vector<int>t(26);
        for(auto &i:adj[src]){
            if(visited[i]==0){
                vector<int>mid=dfs(adj,visited,i,s);
                int count=0;
                for(auto &j:mid){
                    t[count]+=j;
                    count++;
                }
            }
        }
        t[s[src]-'a']+=1;
        ans[src] = t[s[src]-'a'];
        return t;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& v, string s) {
        vector<int>adj[n];
        for(auto &i:v){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n);
        ans.resize(n);
    dfs(adj,visited,0,s);
        return ans;
    }
};