class Solution {
public:
    int matrixScore(vector<vector<int>>& v) {
        for(int i=0;i<v.size();i++){
            if(v[i][0]==1){
                continue;
            }
            for(int j=0;j<v[0].size();j++){
                v[i][j]=!v[i][j];
            }
        }
        int count=0;
        int m=v.size();
        int n=v[0].size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int mx=0;
            for(int j=0;j<m;j++){
                mx+=v[j][i];
            }
            mx = max(mx,m-mx);
            ans+=(1<<count)*mx;
            count++;
        }
        return ans;
    }
};