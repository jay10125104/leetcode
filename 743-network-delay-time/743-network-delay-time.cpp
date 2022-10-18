class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int count=0;
        n = n+1;
        vector<pair<int,int>>adj[n];
        for(auto i:t){
            adj[i[0]].push_back({i[2],i[1]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
        q.push({0,k});
        int ans = INT_MIN;
        vector<int>visited(n);
        // vector<int>ans(n,INT_MAX);
        while(q.size()){
            auto it = q.top();
            q.pop();
            // cout<<"df";
            if(visited[it.second]==1){
                continue;
            }
            count++;
            visited[it.second]=1;
            ans=max(ans,it.first);
            for(auto i:adj[it.second]){
                if(visited[i.second]==0){
                    q.push({it.first+i.first,i.second});
                }
            }
            
        }
        n--;
        if(count==n){
            return ans;
        }
        else{
            return -1;
        }
    }
};