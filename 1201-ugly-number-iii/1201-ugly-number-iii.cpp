class Solution {
public:
    long long int lcm(long long int a,long long int b){
        return (a*b)/__gcd(a,b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        a = (long long int)a;
        b = (long long int)b;
        c = (long long int)c;
        long long int low = 1;
        long long int high = min({a,b,c})*n;
        long long int ans = -1;
        while(low<=high){
            long long int mid = (low+high)/2;
            long long int x  = (long long int)((mid/a) + (mid/b) + (mid/c) - (mid/lcm(a,b)) - (mid/lcm(b,c)) - (mid/lcm(a,c)) + (long long int)(mid/lcm(a,lcm(b,c))));
            if(x>=n){
                if(x==n){
                    ans = mid;
                }
                high = mid-1; 
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};