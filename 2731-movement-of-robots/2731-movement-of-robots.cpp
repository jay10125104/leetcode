class Solution {
public:
    int sumDistance(vector<int>& v, string s, int d) {
        long long int rsum=0;
        long long int lsum=0;
        for(int i=0;i<v.size();i++){
            if(s[i]=='R'){
                v[i]+=d;
            }
            else{
                v[i]-=d;
            }
            rsum+=v[i];
            rsum%=1000000007;
        }
        sort(v.begin(),v.end());
        long long int ans=0;
        long long int mod=1000000007;
        for(long long int i=0;i<v.size();i++){
            long long int left = i;
            long long int right = (long long int)v.size()-i;
            ans = (ans%mod + (rsum%mod-(right*1ll*v[i])%mod)%mod)%mod;
            ans+=mod;
            ans%=mod;
            rsum-=v[i];
        }
        return ans;
    }
};