class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& v, vector<int>& t) {
        vector<int>adj[n+1];
        vector<int>indegree(n+1);
        for(auto i:v){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int>q;
        vector<int>dis(n+1);
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                dis[i]=0;
            }
        }
        int ans=0;
        while(q.size()){
            int x = q.size();
            while(x--){
                auto it = q.front();
                q.pop();
                dis[it]+=(t[it-1]);
                ans = max(ans,dis[it]);
                // cout<<it<<" ";
                // mx = max(t[it-1],mx);
                for(auto i:adj[it]){
                    indegree[i]--;
                    dis[i] = max(dis[i],dis[it]);
                    if(indegree[i]==0){
                        q.push(i);
                    }
                }
                
            }
            // cout<<endl;
           
        }
        return ans;
        
    }
};