class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& prev) {
        int size=m;
        for(int i=0;i<group.size();i++){
            if(group[i]==-1){
                group[i]=size++;
            }
        }
        vector<int>adj[n];
        vector<int>indegree(n);
        vector<int>adj3[size];
        vector<int>indegree2(size);
        for(int i=0;i<prev.size();i++){
            for(auto &j:prev[i]){
                indegree[i]++;
                adj[j].push_back(i);
                int group1=group[i];
                int group2=group[j];
                if(group1==group2){
                    continue;
                }
                indegree2[group1]++;
                adj3[group2].push_back(group1);
            }
        }
        vector<int>v;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>adj1[size];
        while(q.size()){
            int x = q.front();
            q.pop();
            adj1[group[x]].push_back(x);
            for(auto &i:adj[x]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            } 
        }
        for(int i=0;i<size;i++){
            if(indegree2[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        int count=0;
        while(q.size()){
            int x = q.front();
            q.pop();
            count++;
            for(auto &i:adj1[x]){
                ans.push_back(i);
            }
            for(auto &i:adj3[x]){
                indegree2[i]--;
                if(indegree2[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;
    }
};