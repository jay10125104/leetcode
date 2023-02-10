class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26];
        int mx=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.size();i++){
            int x = s[i]-'a';
            int mid=0;
            for(int j=0;j<26;j++){
                if(abs(x-j)<=k){
                    mid = max(mid,dp[j]+1);
                }
            }
            dp[x] = mid;
            mx = max(mx,dp[x]);
        }
        return mx;
        
    }
};