class Solution {
public:
    bool isvovel(char s){
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=isvovel(s[0]);
        for(int i=1;i<s.size();i++){
            dp[i]+=isvovel(s[i]);
            dp[i]+=dp[i-1];
        }
        int ans = dp[k-1];
        for(int i=k;i<n;i++){
            ans=max(ans,dp[i]-dp[i-k]);
        }
        return ans;
    }
};