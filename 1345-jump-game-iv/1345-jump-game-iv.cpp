class Solution {
public:
    int minJumps(vector<int>& v) {
        int n=v.size();
        vector<int>visited(n);
        queue<int>q;
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++){
            m[v[i]].push_back(i);
        }
        q.push(0);
        visited[0]=1;
        int count=0;
        map<int,int>vis;
        while(q.size()){
            int x = q.size();
            while(x--){
                int it = q.front();
                q.pop();
                if(it==n-1){
                    return count;
                }
                if(it>=1 && visited[it-1]==0){
                    q.push(it-1);
                    visited[it-1]=1;
                }
                if(it<(n-1) && visited[it+1]==0){
                    q.push(it+1);
                    visited[it+1]=1;
                }
                if(vis[v[it]]==1){
                    continue;
                }
                vis[v[it]]=1;
                for(auto &i:m[v[it]]){
                    if(visited[i]==0){
                        q.push(i);
                        visited[i]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};