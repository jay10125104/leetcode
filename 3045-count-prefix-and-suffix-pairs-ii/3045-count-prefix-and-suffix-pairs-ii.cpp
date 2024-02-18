class Solution {
public:
    long long int m=1e9+7;
    long long int prime=31;
    long long int binaryexpo(long long int a,long long int b){
        long long int ans=1;
        while(b){
            if(b&1){
                ans = (ans*a)%m;
            }
            a = (a*a)%m;
            b=b/2;
        }
        return ans;
    }
    long long countPrefixSuffixPairs(vector<string>& v) {
        map<long long int ,long long int>mp;
        long long int ans=0;
        for(int i=0;i<v.size();i++){
            string s=v[i];
            int n=s.size();
            long long int prefix=0;
            long long int suffix=0;
            for(int j=0;j<n;j++){
                prefix = (((((prefix%m)*(prime%m))+m)%m +  (s[j]-'a'+1)%m)+m)%m;
                suffix = (((((s[n-j-1]-'a'+1)*binaryexpo(prime,j))%m)+m)%m + suffix%m)%m;
                if(prefix==suffix){
                    ans+=mp[prefix];
                }
            }
            mp[prefix]++;
        }
        return ans;
    }
};