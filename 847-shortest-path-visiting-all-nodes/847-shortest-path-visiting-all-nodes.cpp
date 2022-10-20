class Solution {
public:
    int shortestPathLength(vector<vector<int>>& v) {
        //not a simple bfs;
        map<pair<int,int>,int>visited;
        queue<pair<pair<int,int>,int>>q;
        // assume this set as {{a,b},c};
        // a ->currnode , b->the path which we have yet covered c->cost;
        for(int i=0;i<v.size();i++){
            int mask = 1<<i;
            q.push({{i,mask},0});
            visited[{i,mask}]=1;
        }
        int req = pow(2,v.size())-1;
        while(q.size()){
            auto it = q.front();
            q.pop();
            if(it.first.second==req){
                return it.second;
            }
            for(auto i:v[it.first.first]){
                int currmask = it.first.second;
                int to_be_masked = 1<<i;
                currmask = to_be_masked|currmask;
                if(visited[{i,currmask}]==0){
                    q.push({{i,currmask},it.second+1});
                    visited[{i,currmask}]=1;
                }
            }
            
        }
        return -1;
    }
};