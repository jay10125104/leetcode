class Solution {
public:
int dp[1001][5];
int mod=1000000007;
void helper(vector<int>&mid,int mask){
        if(mask==0){
            mid.push_back(0);
            mid.push_back(1);
            mid.push_back(2);
        }
        else if(mask==1){
            mid.push_back(1);
            mid.push_back(3);
        }
        else if(mask==2){
            mid.push_back(1);
            mid.push_back(3);
        }   
        else{
            mid.push_back(0);
        }
}
int ans(int idx,int b,int mask){
    if(idx>b){
        return 0;
    }
    if(idx==b){
        if(mask==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(dp[idx][mask]!=-1){
        return dp[idx][mask];
    }
    else{
        int sol=0;
        vector<int>mid;
        helper(mid,mask);
        if(mask==0){
            sol = (sol%mod + ans(idx+2,b,0)%mod)%mod;
        }
        for(auto &i:mid){
            sol = (sol%mod + ans(idx+1,b,i)%mod)%mod;
        }
        return dp[idx][mask] = sol;
    }
}
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return ans(0,n,0);
    }
};