class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& v) {
        int m = v.size();
        int n=v[0].size();
        int dp1[m][n];
        memset(dp1,0,sizeof(dp1));
        int dp2[m][n];
        memset(dp2,0,sizeof(dp2));
        int dp3[m][n];
        memset(dp3,0,sizeof(dp3));
        int dp4[m][n];
        memset(dp4,0,sizeof(dp4));
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    count++;
                }
                else{
                    count=0;
                }
                dp1[i][j]=count;
                
            }
        }
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(v[i][j]){
                    count++;
                }
                else{
                    count=0;
                }
                dp2[i][j]=count;
                
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(v[j][i]){
                    count++;
                }
                else{
                    count=0;
                }
                dp3[j][i]=count;
                
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=m-1;j>=0;j--){
                if(v[j][i]){
                    count++;
                }
                else{
                    count=0;
                }
                dp4[j][i]=count;
                
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    continue;
                }
                int mn = min(dp1[i][j],dp3[i][j]);
                int req=2;
                int a=i-1;
                int b=j-1;
                int sol=1;
                while(mn && a>=0 && b>=0){
                    if(dp2[a][b]>=req && dp4[a][b]>=req){
                        sol = req;
                    }
                    req++;
                    mn--;
                    a--;
                    b--;
                }
                ans = max(ans,sol*sol);
            }
    }
        return ans;
    }
};