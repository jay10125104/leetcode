class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
    int dp[200001];
        memset(dp,0,sizeof(dp));
        int ans=0;
        // map<int,int>m;
        for(auto &i:nums){
            dp[i]++;
            
        }
        long long int sum=0;
        for(int i=0;i<200001;i++){
            sum+=dp[i];
            if(sum){
                sum--;
            }
            ans+=sum;
        }
        return ans;
    }
};