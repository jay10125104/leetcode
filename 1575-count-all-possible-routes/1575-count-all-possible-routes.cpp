class Solution {
public:
    int dp[101][201];
    int mod=1000000007;
    int ans(vector<int>&v,int start,int fuel,int end){
        if(fuel<0){
            return 0;
        }
        else if(dp[start][fuel]!=-1){
            return dp[start][fuel];
        }
        int sol=0;
        if(start==end){
            sol++;
        }
            long long int mid=0;
            for(int i=0;i<v.size();i++){
                if((i!=start)){
                    sol = (sol%mod + ans(v,i,fuel-abs(v[start]-v[i]),end)%mod)%mod;
                }
            }
            return dp[start][fuel]=sol%mod;
    }
    int countRoutes(vector<int>& v, int start, int end, int fuel) {
        memset(dp,-1,sizeof(dp));
        return ans(v,start,fuel,end);
        // return sol;
    }
};