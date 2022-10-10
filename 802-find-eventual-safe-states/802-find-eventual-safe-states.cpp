class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        vector<int>adj[v.size()];
        vector<int>indegree(v.size());
        for(int i=0;i<v.size();i++){
            for(auto it:v[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<v.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto i:adj[x]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};