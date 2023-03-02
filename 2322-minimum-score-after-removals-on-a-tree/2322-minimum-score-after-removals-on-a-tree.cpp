class Solution {
public:
    int dp1[1001];
    vector<int>nums;
    int txorr=0;
    int ans = INT_MAX;
    int dfs1(vector<int>adj[],int rsrc,int rparent,int src,int parent,int first){
        int xorr=0;
        for(auto &i:adj[src]){
            if(i==parent){
                continue;
            }
            if(src==rparent && i==rsrc){
                continue;
            }
            else{
                int x = dfs1(adj,rsrc,rparent,i,src,first);
                int curr = x;
                int prev = first;
                int next = (txorr^prev^curr);
                xorr^=x;
                
                ans = min(ans,max({curr,prev,next})-min({curr,prev,next}));
            }
        }
        return xorr^nums[src];
    }
    int dfs(vector<int>adj[],int src,int parent){
        int xorr=0;
        for(auto &i:adj[src]){
            if(i!=parent){
                int x = dfs(adj,i,src);
                xorr^=x;
                dfs1(adj,i,src,0,-1,x);
            }
        }
        return xorr^nums[src];
    }
    int minimumScore(vector<int>& num, vector<vector<int>>& edges) {
        nums = num;
        int n=nums.size();
        for(auto &i:nums){
            txorr^=i;
        }
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // memset(dp,0,sizeof(dp));
        dfs(adj,0,-1);
        return ans;
    }
};