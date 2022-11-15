class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            int first = dp[p2]*2;
            int second = dp[p3]*3;
            int third = dp[p5]*5;
            int mn = min({first,second,third});
            if(first==mn){
                p2++;
            }
            if(second==mn){
                p3++;
            }
            if(third==mn){
                p5++;
            }
            dp[i] = mn;
        }
        return dp[n-1];
    }
};