class Solution {
public:
    long long int op1(long long int a, long long int b, long long int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    long long int op2(long long int a, long long int b, long long int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    int knightDialer(int n) {
        vector<string>s = {"46","68","79","48","039","","017","26","13","24","46"};
        if(n==1){
            return 10;
        }
        else{
            long long int m = 1000000007;
            vector<long long int>v(10,1);
            long long int sum=0;
            vector<long long int>dp(n+1,0);
            for(int i=2;i<=n;i++){
                vector<long long int>fresh(10,0);
                for(int j=0;j<=9;j++){
                    int x = v[j];
                    for(auto it:s[j]){
                        fresh[it-'0'] = op1(fresh[it-'0'],x,m);
                    }
                }
                v = fresh;
            }
            for(auto i:v){
                sum = op1(sum,i,m);
            }
            return sum;
        }
    }
};