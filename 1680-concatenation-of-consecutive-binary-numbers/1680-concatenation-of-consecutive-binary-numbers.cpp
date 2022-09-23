class Solution {
public:
    int concatenatedBinary(int n) {
        long long int mod = 1000000007;
        long long int ans=0;
        for(int i=1;i<=n;i++){
            long long int mid = log2(i)+1;
            long long int mid2 = (((ans<<mid)%mod)+(i%mod))%mod;
            ans = mid2;
        }
        return ans;
    }
};