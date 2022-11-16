class Solution {
public:
    bool isInterleave(string s, string t, string ans) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        if((s.size()+t.size())!=ans.size()){
            return false;
        }
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    int k = i+j;
                    dp[i][j]=0;
                    if(i-1>=0 && s[i-1]==ans[k-1]){
                        dp[i][j]|=dp[i-1][j];
                    }
                    
                    if(j-1>=0 && t[j-1]==ans[k-1]){
                        dp[i][j]|=dp[i][j-1];
                    }
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};