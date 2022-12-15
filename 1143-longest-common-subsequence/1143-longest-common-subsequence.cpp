class Solution {
public:
    int dp[1001][1001];
    int ans(string &s,string &t,int idx1,int idx2){
        if(idx1==s.size() || idx2==t.size()){
            return 0;
        }
        else if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        else{
            if(s[idx1]==t[idx2]){
                return 1+ans(s,t,idx1+1,idx2+1);
            }
            else{
                return dp[idx1][idx2] = max(ans(s,t,idx1+1,idx2),ans(s,t,idx1,idx2+1));
            }
        }
    }
    int longestCommonSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return ans(s,t,0,0);
    }
};