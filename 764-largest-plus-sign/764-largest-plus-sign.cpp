class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& vi) {
        int down[n+1][n+1];
        int up[n+1][n+1];
        int left[n+1][n+1];
        int right[n+1][n+1];
        int v[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i][j]=1;
            }
        }
        // cout<<v[0][0];
        for(auto &i:vi){
            v[i[0]][i[1]]=0;
        }
        
        memset(down,0,sizeof(down));
        memset(up,0,sizeof(up));
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        int ans=0;
        for(int j=0;j<n;j++){
            ans=0;
            for(int i=n-1;i>=0;i--){
                down[i][j] = ans;
                if(v[i][j])
                    ans++;
                else
                    ans=0;
            }
        }
        for(int j=0;j<n;j++){
            ans=0;
            for(int i=0;i<n;i++){
                up[i][j] = ans;
                if(v[i][j])
                    ans++;
                else
                    ans=0;
            }
        }
        for(int i=0;i<n;i++){
            ans=0;
            for(int j=n-1;j>=0;j--){
                right[i][j] = ans;
                if(v[i][j])
                    ans++;
                else
                    ans=0;
            }
        }
        for(int i=0;i<n;i++){
            ans=0;
            for(int j=0;j<n;j++){
                left[i][j] = ans;
                if(v[i][j])
                    ans++;
                else
                    ans=0;
            }
        }
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    ans=max(ans,1+min({left[i][j],right[i][j],down[i][j],up[i][j]}));
                }
            }
        }
        return ans;
    }
};