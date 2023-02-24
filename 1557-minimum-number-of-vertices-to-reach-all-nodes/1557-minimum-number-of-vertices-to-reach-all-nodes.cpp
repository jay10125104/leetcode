class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n);
        // vector<int>indegree1(n);
        vector<int>adj[n];
        for(auto &i:trust){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};