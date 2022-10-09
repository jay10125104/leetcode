class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& v, int s, int t) {
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                m[v[i][j]].push_back(i);
            }
        }
        queue<int>q;
        q.push(s);
        map<int,int>busv;
        map<int,int>visited;
        visited[s]=1;
        int count=0;
        // cout<<"sf";
        while(q.size()){
            int x = q.size();
            while(x--){
                // cout<<"kp";
                int k = q.front();
                q.pop();
                if(k==t){
                    return count;
                }
                auto busnumber = m[k];
                for(auto i:busnumber){
                    if(busv[i]==0){
                        for(auto j:v[i]){
                            if(visited[j]==0){
                                q.push(j);
                                visited[j]=1;
                            }
                        }
                        busv[i]=1;
                    }
                }
                
            }
            count++;
        }
        return -1;
    }
};