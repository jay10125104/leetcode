class Solution {
public:
    int dp[100][100];
    int ans(vector<int>&v,int idx,int M){
        if(idx>=v.size()){
            return 0;
        }
        else if(dp[idx][M]!=-1){
            return dp[idx][M];
        }
        else{
            int mx = INT_MIN;
            int sum=0;
            for(int i=0;i<2*M;i++){
                if((idx+i)<v.size()){
                sum+=v[idx+i];
                mx = max(mx,sum-ans(v,idx+i+1,max(M,i+1)));
                }
            }
            return dp[idx][M] = mx;
        }
    }
    int stoneGameII(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto &i:v){
            sum+=i;
        }
        return (sum+ans(v,0,1))/2;
    }
};