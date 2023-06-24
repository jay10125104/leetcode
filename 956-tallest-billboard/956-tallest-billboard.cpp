class Solution {
public:
    int dp[20][10005];
    long long int ans(vector<int>&v,int idx,int sum){
        if(idx==v.size()){
            if(sum==0){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        else if(dp[idx][sum+5000]!=-1){
            return dp[idx][sum+5000];
        }
        else{
            int x = ans(v,idx+1,sum);
            int y = ans(v,idx+1,sum+v[idx])+v[idx];
            int z = v[idx]+ans(v,idx+1,sum-v[idx]);
            return dp[idx][sum+5000]=max({x,y,z});
        }
    }
    int tallestBillboard(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        return ans(v,0,0)/2;
    }
};