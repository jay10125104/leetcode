class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int>indegree(n);
        vector<int>adj[n];
        for(int i=0;i<l.size();i++){
            if(l[i]!=-1){
            adj[i].push_back(l[i]);
            indegree[l[i]]++;
            }
        }
        for(int i=0;i<r.size();i++){
            if(r[i]!=-1){
            adj[i].push_back(r[i]);
            indegree[r[i]]++;
            }
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]>=2){
                return false;
            }
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        if(count>=2){
            return false;
        }
        while(q.size()){
            auto it = q.front();
            q.pop();
            for(auto i:adj[it]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    count++;
                }
            }
        }
        return count==n;
    }
};