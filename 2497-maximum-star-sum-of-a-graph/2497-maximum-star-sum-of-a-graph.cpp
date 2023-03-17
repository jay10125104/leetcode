class Solution {
public:
    int maxStarSum(vector<int>& v, vector<vector<int>>& edges, int k) {
        int n=v.size();
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(v[i[1]]);
            adj[i[1]].push_back(v[i[0]]);
        }
        int ans=INT_MIN;
        int count=0;
        for(int j=0;j<n;j++){
            int sum=v[count];
            sort(adj[j].begin(),adj[j].end(),greater<int>());
            for(int i=0;i<min(k,(int)adj[j].size());i++){
                if(adj[j][i]>0)
                sum+=adj[j][i];
            }
            ans=max(ans,sum);
            count++;
        }
        return ans;
    }
};