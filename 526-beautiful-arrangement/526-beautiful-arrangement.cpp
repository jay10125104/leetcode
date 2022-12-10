class Solution {
public:
    int dp[16][1<<16];
    int ans(int n,int idx,int mask){
        if(mask==((1<<n)-1)){
            return 1;
        }
        else if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        else{
            int sol=0;
            for(int i=0;i<n;i++){
                int Mask = (1<<i);
                int val = i+1;
                int id = idx+1;
                if((mask&Mask)==0 && ((val%id)==0 || ((id%val)==0))){
                    sol+=ans(n,idx+1,mask|Mask);
                }
            }
            return dp[idx][mask] = sol;
        }
    }
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return ans(n,0,0);
    }
};