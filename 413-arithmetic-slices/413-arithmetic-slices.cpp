class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n=v.size();
        set<pair<int,int>>dp;
        int ans=0;
        // cout<<"df";
        // memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                int len = (j-i+1);
                if(len==3){
                    bool x = ((v[i+1]-v[i])==(v[i+2]-v[i+1]));
                    if(x)
                        dp.insert({i,j});
                }
                else if(len>3){
                    if(dp.count({i,j-1})){
                    bool x = ((v[j]-v[j-1])==(v[j-1]-v[j-2]));
                        // dp[i][j]=x;
                        if(x)
                        dp.insert({i,j});
                    }
                }
                ans+=dp.count({i,j});
            }
        }
        return ans;
    }
};