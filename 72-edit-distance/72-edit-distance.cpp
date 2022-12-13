class Solution {
public:
    int dp[501][501];
    int ans(string s,string t,int idx1,int idx2){
        if(idx1==s.size() && idx2==t.size()){
            return 0;
        }
        if(idx1==s.size()){
            return t.size()-idx2;
        }
        else if(idx2==t.size()){
            return s.size()-idx1;
        }
        else if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        else{
            if(s[idx1]==t[idx2]){
                return dp[idx1][idx2] = ans(s,t,idx1+1,idx2+1);
            }
            else{
                return dp[idx1][idx2] =1+min({ans(s,t,idx1+1,idx2),ans(s,t,idx1,idx2+1),ans(s,t,idx1+1,idx2+1)});
            }
        }
    }
    int minDistance(string s, string t) {
        memset(dp,-1,sizeof((dp)));
        return  ans(s,t,0,0);
    }
};