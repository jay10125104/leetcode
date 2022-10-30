class Solution {
public:
    int ans(long long int n){
        int count=0;
        string mid = to_string(n);
        for(auto &i:mid){
            count+=(i-'0');
        }
        return count;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long int req = n;
        int count=1;
        while(ans(n)>target){
            long long int rem = pow(10,count);
            count++;
            long long int left = n%rem;
            n+=(rem-left);
        }
        return n - req;
    }
};