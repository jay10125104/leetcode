class Solution {
public:
    bool ans(vector<vector<int>>&v,int r,int c,vector<vector<int>>&visited,int &count){
        if(r<0 || c<0 || r==v.size() || c==v[0].size()){
            return false;
        }
        else if(visited[r][c] || v[r][c]==0){
            return true;
        }
        visited[r][c]=1;
        count++;
        bool x = ans(v,r+1,c,visited,count);
        bool y = ans(v,r-1,c,visited,count);
        bool z = ans(v,r,c-1,visited,count);
        bool t = ans(v,r,c+1,visited,count);
        if(x && y && z && t){
            return true;
        }
        else{
            v[r][c]=0;
            return false;
        }
    }
    int numEnclaves(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        int ans1=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && v[i][j]){
                    int count=0;
                    if(ans(v,i,j,visited,count)){
                        ans1+=count;
                    }
                }
            }
        }
        return ans1;
    }
};