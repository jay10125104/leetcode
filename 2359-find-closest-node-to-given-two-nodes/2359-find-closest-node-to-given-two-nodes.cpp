class Solution {
public:
    int closestMeetingNode(vector<int>& v, int node1, int node2) {
        vector<int>adj[v.size()];
        for(int i=0;i<v.size();i++){
            if(v[i]!=-1)
            adj[i].push_back(v[i]);
        }
    
    queue<vector<int>>q;
        q.push({node1,0});
        q.push({node2,1});
        int flag=0;
        int ans=INT_MAX;
        int visited[v.size()][2];
        memset(visited,0,sizeof(visited));
        while(q.size()){
            int x = q.size();
            while(x--){
            auto it = q.front();
            q.pop();
            visited[it[0]][it[1]]=1;
            if(visited[it[0]][!it[1]]){
                ans = min(ans,it[0]);
                flag=1;
            }
            for(auto i:adj[it[0]]){
                if(visited[i][it[1]]==0){
                    q.push({i,it[1]});
                }
            }
            }
            if(flag){
                return ans;
            }
            
        }
        return -1;
    }
};