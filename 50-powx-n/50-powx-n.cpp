class Solution {
public:
    double myPow(double x, int n) {
        int m=n;
        double ans=1;
        double mid=1;
        while(n){
            if(n&1){
                ans=ans*x;
            }
            x=x*x;
            n/=2;
        }
        if(m<0){
            ans=1.0/ans;
        }
        return ans;
    }
};