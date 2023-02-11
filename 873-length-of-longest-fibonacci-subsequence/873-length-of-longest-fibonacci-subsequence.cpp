class Solution {
public:
    int lenLongestFibSubseq(vector<int>& v) {
        int n=v.size();
        int dp[n][n];
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=2;i<v.size();i++){
            int left = 0;
            int right = i-1;
            while(left<right){
                if(v[left]+v[right]>v[i]){
                    right--;
                }
                else if(v[left]+v[right]<v[i]){
                    left++;
                }
                else{
                    dp[right][i] = dp[left][right]+1;
                    ans = max(ans,dp[right][i]);
                    left++;
                    right--;
                }
            }
        }
        return ans==0?(0):(ans+2);
    }
};