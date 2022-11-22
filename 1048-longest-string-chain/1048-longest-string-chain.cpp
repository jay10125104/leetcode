bool cmp(string &s,string &t){
    return s.size()<t.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& v) {
        sort(v.begin(),v.end(),cmp);
        int n=v.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int ans = 1;
        for(int i=1;i<n;i++){
            // cout<<v[i]<<" ";
            string s = v[i];
            int sz = s.size();
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if((sz-v[j].size())>=2){
                    break;
                }
                else if(sz-v[j].size()){
                    int x=0;
                    int y=0;
                    int sol=0;
                    while(x<sz && y<v[j].size()){
                        if(s[x]!=v[j][y]){
                            sol++;
                            x++;
                        }
                        else{
                            x++;
                            y++;
                        }
                    }
                    if(sol<=1){
                        // cout<<v[i]<<" "<<v[j]<<endl;
                        dp[i] = max(dp[i],dp[j]+1);
                    }
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};