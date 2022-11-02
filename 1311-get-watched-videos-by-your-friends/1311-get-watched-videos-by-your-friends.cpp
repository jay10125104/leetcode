bool cmp(pair<string,int>&a,pair<string,int>&b){
    if(a.second!=b.second){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& f, int id, int level) {
        int n = w.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto &j:f[i]){
            adj[i].push_back(j);
            }
        }
        queue<int>q;
        q.push(id);
        vector<int>visited(n);
        visited[id]=1;
        while(level--){
            int x = q.size();
            while(x--){
                auto it = q.front();
                q.pop();
                // visited[it]=1;
                for(auto &i:adj[it]){
                    if(visited[i]==0){
                        q.push(i);
                        visited[i]=1;
                    }
                }
                
            }
        }
        map<string,int>m;
        while(q.size()){
            auto it = q.front();
            q.pop();
            for(auto &i:w[it]){
                m[i]++;
            }
        }
        vector<pair<string,int>>sol;
        for(auto &i:m){
            sol.push_back({i.first,i.second});
        }
        sort(sol.begin(),sol.end(),cmp);
        vector<string>ans;
        for(auto &i:sol){
            ans.push_back(i.first);
        }
        return ans;
    }
};