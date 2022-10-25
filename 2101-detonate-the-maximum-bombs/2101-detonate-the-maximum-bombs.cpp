class Solution {
public:
    void dfs(vector<vector<int>>&v,vector<int>&visited,int &count,int src){
        count++;
        visited[src]=1;
        long long int x = v[src][0];
        long long int y = v[src][1];
        long long int r = pow(v[src][2],2);
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
           long long int dis = pow((x-v[i][0]),2) + pow((y-v[i][1]),2);
                if(dis<=r){
                    dfs(v,visited,count,i);
                }
                }
            
        }
    }
    int maximumDetonation(vector<vector<int>>& v) {
        int n = v.size();
         int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>visited(n);
            int count=0;
            
            dfs(v,visited,count,i);
            ans  = max(ans,count);
        }
        return ans;
    }
};