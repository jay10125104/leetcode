class Solution {
public:
    int dp[100000];
    vector<int> corpFlightBookings(vector<vector<int>>& v, int n) {
        memset(dp,0,sizeof(dp));
        for(auto &i:v){
            dp[i[0]]+=i[2];
            dp[i[1]+1]-=i[2];
        }
        for(int i=1;i<100000;i++){
            dp[i]+=dp[i-1];
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(dp[i]);
        }
        return ans;
    }
};