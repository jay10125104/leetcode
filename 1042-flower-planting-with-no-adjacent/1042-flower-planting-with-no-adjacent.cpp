class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& graph) {
        vector<int>adj[n];
        for(auto &i:graph){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int>ans(n,0);
        vector<int>visited(n);
        cout<<"sdf";
        for(int i=0;i<n;i++){
            vector<int>v(4);
            for(auto it:adj[i]){
                v[ans[it]]++;
            }
            int j;
            for(j=1;j<=3;j++){
                if(v[j]==0){
                    break;
                }
            }
            cout<<1;   
            ans[i] = j;
        }
    
    return ans;
    }
};