class Solution {
public:
    int parent[100001];
    int distance[100001];
    void dfs(vector<int>adj[],int src,int parents){
        for(auto &i:adj[src]){
            if(i!=parents){
                parent[(int)i]=src;
                distance[i] = distance[src]+1;
                dfs(adj,i,src);
            }
        }
    }
    int ans=INT_MIN;
    void dfs1(vector<int>adj[],int src,vector<int>&amount,int parents,int sum){
        int counter=0;
        sum+=amount[src];
        for(auto &i:adj[src]){
            if(i!=parents){
                counter++;
                dfs1(adj,i,amount,src,sum);
            }
        }
        if(counter==0){
            ans = max(ans,sum);
        }
        sum-=amount[src];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        memset(parent,-1,sizeof(parent));
        memset(distance,0,sizeof(distance));
        dfs(adj,0,-1);
        int src=bob;
        int count=0;
        while(src!=-1){
            if(distance[src]>count){
                amount[src]=0;
            }
            else if(distance[src]==count){
                amount[src]/=2;
            }
            src = parent[src];
            count++;
        }
        dfs1(adj,0,amount,-1,0);
        return ans;
        // return 0;
        
    }
};