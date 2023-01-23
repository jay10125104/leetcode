class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        for(auto i:trust){
            adj[i[0]].push_back(i[1]);
        }
        map<int,int>m;
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                m[it]++;
            }
        }
        for(auto i:m){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(int i=1;i<=n;i++){
            // cout<<i.first<<" "<<i.second<<endl; 
            if(m[i]==n-1 && adj[i].size()==0){
                return i;
            }
        }
        return -1;
    }
};