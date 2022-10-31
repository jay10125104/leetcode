class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<int>adj[n];
        vector<int>indegree(n);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[1]]++;
            indegree[i[0]]++;
        }   
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
             q.push(i);
                // ans.push_back(i);
            }
            
        }
        if(n==1){
            return {0};
        }
        
        while(q.size()){
            int x=  q.size();
            vector<int>mid;
            while(x--){
                auto it = q.front();
                q.pop();
                mid.push_back(it);
                for(auto i:adj[it]){
                    indegree[i]--;
                    if(indegree[i]==1){
                        q.push(i);
                    }
                }
            }
            ans = mid;
        }
        return ans;
    }
};