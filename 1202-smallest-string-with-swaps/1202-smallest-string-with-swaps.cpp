class Solution {
public:
    void dfs(vector<int>adj[],int src,vector<int>&visited,vector<char>&c,vector<int>&idx,string &s){
        visited[src] = 1;
        c.push_back(s[src]);
        idx.push_back(src);
        for(auto i:adj[src]){
            if(visited[i]==0){
                dfs(adj,i,visited,c,idx,s);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int>visited(n);
        vector<int>adj[n];
        for(auto i:pairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        map<int,char>m;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                vector<char>c;
                vector<int>idx;
                dfs(adj,i,visited,c,idx,s);
                sort(c.begin(),c.end());
                sort(idx.begin(),idx.end());
                for(int j=0;j<idx.size();j++){
                    m[idx[j]] = c[j];
                }
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            ans+=m[i];
        }
        return ans;
    }
};