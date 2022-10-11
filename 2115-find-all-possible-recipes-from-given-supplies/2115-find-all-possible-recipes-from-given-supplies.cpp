class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ig, vector<string>& s) {
        int count=1;
        map<string,int>m1;
        map<int,string>m2;
        for(auto i:r){
            if(m1.find(i)==m1.end()){
                m1[i] = count;
                m2[count] = i;
                count++;
            }
        }
        map<int,int>sup;
        for(auto j:ig){
            for(auto i:j){
            if(m1.find(i)==m1.end()){
                m1[i] = count;
                m2[count] = i;
                count++;
            }
            }
        }
        for(auto i:s){
            if(m1.find(i)==m1.end()){
                m1[i] = count;
                m2[count]=i;
                count++;
            }
            sup[m1[i]]=1;
        }
        vector<int>adj[count];
        vector<int>indegree(count);
        for(int i=0;i<r.size();i++){
            int x = m1[r[i]];
            for(auto j:ig[i]){
                adj[m1[j]].push_back(x);
                indegree[x]++;
            }
        }
        queue<int>q;
        
        for(int i=0;i<count;i++){
            if(sup[i] && indegree[i]==0){
                q.push(i);
            }
        }
        map<string,int>ans;
        while(q.size()){
            int x = q.front();
            q.pop();
            ans[m2[x]]=1;
            for(auto i:adj[x]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        vector<string>sol;
        for(auto i:r){
            if(ans[i]){
                sol.push_back(i);
            }
        }
        return sol;
    }
};