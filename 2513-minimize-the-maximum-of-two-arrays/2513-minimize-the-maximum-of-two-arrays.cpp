class Solution {
long long int lcmm(long long int a,long long int b){
    return (a*b)/__gcd(a,b);
}
public:
    int ans(int d1,int d2,int u1,int u2,long long int mid){
        long long int A = mid/d1;
        long long int B = mid/d2;
        long long int A_ = mid-A;
        long long int B_ = mid-B;
        long long int AIB = mid/(long long int)lcmm(d1,d2);
        long long int AuB = A+B-AIB;
        long long int req = mid-AuB;
        long long int req1 = ((A_-req)>=u1)?(0):(u1-(A_-req));
        long long int req2 = ((B_- req)>=u2)?(0):(u2-(B_-req));
        // cout<<A_<<" "<<B_<<" "<<u1;
        return (req1+req2)<=req;
    }
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long int low = 0;
        long long int high = 1e12;
        long long int sol = u1+u2;
        // cout<<ans(d1,d2,u1,u2,13);
        while(low<=high){
            long long int mid = (low+high)/2;
            if(ans(d1,d2,u1,u2,mid)){
                sol = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return sol;
    }
};