class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int>ans(n-1);
        for(int mask=1;mask<(1<<n);mask++){
            int count1=0;
            int t = __builtin_popcount(mask);
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0]-1;
                int v = edges[j][1]-1;
                if(((mask&(1<<u))!=0) && (mask&(1<<v))!=0){
                    count1++;
                }
            }
            if((count1+1)==t){
                // cout<<mask<<"@\n";
                int sol=0;
                for(int k=0;k<16;k++){
                    if(mask&(1<<k)){
                        queue<int>q;
                        q.push(k);
                        int count=0;
                        vector<int>visited(16);
                        while(q.size()){
                            count++;
                            int x=q.size();
                            while(x--){
                                int it = q.front();
                                q.pop();
                                visited[it]=1;
                                for(auto iter:adj[it]){
                                    if((mask&(1<<iter)) && visited[iter]==0){
                                        q.push(iter);
                                    }
                                }
                            }
                        }
                        sol = max(sol,count);
                    }
                }
                if(sol>1){
                    // cout<<mask<<" "<<sol<<endl;
                    ans[sol-2]++;
                }
            }
        }
        return ans;
    }
};