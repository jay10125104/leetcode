class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n=s.size();
        int dp[n];
        map<char,int>m;
        memset(dp,0,sizeof(dp));
        m[s[0]]=1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            char req = '*';
            if(s[i-1]=='z'){
                req='a';
            }
            else{
                req = (s[i-1]+1);
            }
            if(s[i]==req){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i]=1;
            }
            m[s[i]]=max(m[s[i]],dp[i]);
        }
        long long int ans=0;
        for(auto &i:m){
            // cout<<i.first<<" "<<i.second<<endl; 
            ans+=i.second;
        }
        return ans;
    }
};