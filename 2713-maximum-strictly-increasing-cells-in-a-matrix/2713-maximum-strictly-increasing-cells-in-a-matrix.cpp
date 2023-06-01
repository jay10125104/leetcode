class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& v) {
        unordered_map<int,vector<pair<int,int>>>idx;
        unordered_map<int,int>value;
        int m=v.size();
        int n=v[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                value[v[i][j]]++;
                idx[v[i][j]].push_back({i,j});
            }
        }
        vector<int>t;
        for(auto &i:value){
            t.push_back(i.first);
        }
        sort(t.rbegin(),t.rend());
        // memset(dp,0,sizeof(dp));
        
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        int ans=0;
        for(auto &i:t){
                vector<int>mid;
            for(auto &k:idx[i]){
                    int x = k.first;
                    int y = k.second;
                    int mx=max(row[x],col[y])+1;
                // cout<<i<<" "<<x<<" "<<y<<" "<<mx<<endl;
                    mid.push_back(mx);
                    ans=max(ans,mx);
            }
                int count=0;
                for(auto &k:idx[i]){
                    int x = k.first;
                    int y = k.second;
                    row[x]=max(row[x],mid[count]);
                    col[y]=max(col[y],mid[count++]);
                }
            
        }
        return ans;
        
        
        
        
    }
};