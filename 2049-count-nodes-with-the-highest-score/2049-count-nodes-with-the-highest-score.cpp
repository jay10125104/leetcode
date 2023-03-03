class Solution {
public:
    int n;
    long long int ans = 0;
    long long int mx=0;
    map<long long int,int>m;
    int dfs(vector<int>adj[],int src,int parent){
        int x=0;
        long long int pro=1;
        for(auto &i:adj[src]){
            if(i!=parent){
                int y=dfs(adj,i,src);
                x+=y;
                pro*=y;
            }
        }
        long long int two = (n-x-1);
        if(!two){
            two=1;
        }
        m[pro*two]++;
        mx = max(mx,pro*two);
        return x+1;
    }
    int countHighestScoreNodes(vector<int>& parent) {
        n = parent.size();
        vector<int>adj[n];
        for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        dfs(adj,0,-1);
        // cout<<mx<<endl;
        return m[mx];
    }
};