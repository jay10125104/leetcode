class Solution {
public:
    int dp[100001];
    int ans(vector<int>&v,int idx){
        if(idx>=v.size()){
            return 0;
        }
        else if(dp[idx]!=-1){
            return dp[idx];
        }
        int sol = v[idx]-ans(v,idx+1);
        if((idx+1)<v.size())
        sol = max(sol,v[idx]+v[idx+1]-ans(v,idx+2));
        if((idx+2)<v.size())
        sol = max(sol,v[idx]+v[idx+1]+v[idx+2] - ans(v,idx+3));
        return dp[idx] = sol;
    }
    string stoneGameIII(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        long long int x = ans(v,0);
        // cout<<x<<" ";
        return ((x>0)?("Alice"):((x==0)?("Tie"):("Bob")));
    }
};