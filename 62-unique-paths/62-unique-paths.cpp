class Solution {
public:
    int uniquePaths(int m, int n) {
        long long int total = (m+n-2);
        long long int have = (m-1);
        long long int ans=1;
        // int mod = 1000000007;
        for(long long int i=n;i<=total;i++){
            ans=ans*i;
            ans/=(i-n+1);
            // ans = ans%mod;
        }
        return ans;
    }
};