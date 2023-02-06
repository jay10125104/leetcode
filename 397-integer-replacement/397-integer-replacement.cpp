class Solution {
public:
    map<long long int,long long int>m;
    long long int ans(long long int n){
        if(n==1){
            return 0;
        }
        
        else if(n%2){
            return (long long int)(1+min(ans(n-1),ans(n+1)));
        }
        else{
            return 1+ans(n/2);
        }
    }
    int integerReplacement(int n) {
        return ans(n);
    }
};