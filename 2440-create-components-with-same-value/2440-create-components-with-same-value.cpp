class Solution {
public:
    vector<int>v;
    int ans=0;
    int dfs(vector<int>adj[],int src,int parent,int target){
        int sum=v[src];
        for(auto &i:adj[src]){
            if(i!=parent){
                sum+=dfs(adj,i,src,target);
                
            }
        }
        return (sum==target)?(0):(sum);
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0;
        for(auto &i:nums){
            sum+=i;
            v.push_back(i);
        }
        int n=nums.size();
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=0;
        for(int i=1;i<=sum;i++){
            if(sum%i==0){
                int x = dfs(adj,0,-1,i);
                // cout<<x<<endl;
                if(x==0){
                    ans = max(ans,(sum/i)-1);
                }
            }
        }
        return ans;
    }
};