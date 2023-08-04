class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        set<string>v;
    for(auto i:d){
        v.insert(i);
    }
    vector<int>dp(s.size(),0);
    string ans="";
    for(int i=0;i<s.size();i++){
        ans+=s[i];
        // cout<<ans<<" ";
        if(v.find(ans)!=v.end()){
            dp[i]=1;
        }
        else{
            for(int j=0;j<i;j++){
                if(dp[j]==1){
                    string mid = ans.substr(j+1,i-j);
                    // cout<<mid<<" ";
                    if(v.find(mid)!=v.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    // printv(dp);
    if(dp[s.size()-1]){
       return 1;
    }
    else{
        return 0;
    }
    }
};