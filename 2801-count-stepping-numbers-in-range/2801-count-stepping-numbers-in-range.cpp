class Solution {
public:
    long long int mod=1e9+7;
    long long int dp[101][15][2][2];
    long long int ans(string &s,int idx,int prev,int zero,int flag){
        // cout<<prev<<endl;
        if(idx==s.size()){
            return 1;
        }
        else if(dp[idx][prev+1][zero][flag]!=-1){
            return dp[idx][prev+1][zero][flag];
        }
        else{
            long long int sol=0;
            int mn=(s[idx]-'0');
            if(flag==0){
                mn=9;
            }
            // cout<<prev<<" "<<zero<<" "<<mn<<endl;
            for(int i=0;i<=mn;i++){
                if((prev==-1) || (zero) || abs(prev-i)==1){
                    int f=0;
                    int z=0;
                    if((flag==1) && (i==mn)){
                        f=1;
                    }
                    if(zero && i==0){
                        z=1;
                    }
                    sol = ((sol%mod) + (ans(s,idx+1,i,z,f)%mod) + mod)%mod;
                }
            }
            return dp[idx][prev+1][zero][flag] = sol%mod;
        }
    }
    bool check(string &s){
        char prev=s[0];
        cout<<s<<endl;
        for(int i=1;i<s.size();i++){
            if(abs(s[i]-s[i-1])!=1){
                // cout<<s[i]<<endl;
                return false;
            }
        }
        return true;
    }
    int countSteppingNumbers(string low, string high) {
        string mid1=low;
        while(low.size()!=high.size()){
            low='0'+low;
        }
        
        memset(dp,-1,sizeof(dp));
        int ans1=ans(low,0,-1,1,1);
        memset(dp,-1,sizeof(dp));
        int ans2=ans(high,0,-1,1,1);
        return ((ans2-ans1+check(mid1))%mod+mod)%mod;
    }
};