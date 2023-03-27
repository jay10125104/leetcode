class Solution {
public:
    int dp[300001];
    int ans(int n){
        if(n==1){
            return 0;
        }
        else if(dp[n]!=-1){
            return dp[n];
        }
        else{
            int mid;
            if(n%2){
                mid=1+ans(n*3+1);
            }
            else{
                mid = 1+ans(n/2);
            }
            return dp[n] = mid;
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        memset(dp,-1,sizeof(dp));
        for(int i=lo;i<=hi;i++){
            int mid = ans(i);
            v.push_back({mid,i});
            // cout<<mid<<" ";
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};