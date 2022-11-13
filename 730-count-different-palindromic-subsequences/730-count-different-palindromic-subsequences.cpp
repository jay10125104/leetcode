class Solution {
public:
long long int op1(long long int a, long long int b, long long int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
long long int op2(long long int a, long long int b, long long int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
long long int op3(long long int a, long long int b, long long int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    int countPalindromicSubsequences(string s) {
            long long int n=s.size();
    map<char,long long int>m;
    vector<long long int>prev(n);
    for(long long int i=0;i<n;i++){
        auto it = m.find(s[i]);
        if(it!=m.end()){
            prev[i]=m[s[i]];
        }
        else{
            prev[i]=-1;
        }
        m[s[i]]=i;
        
    }
    m.clear();
    long long int MOD=1000000007;
    vector<long long int>next(n);
    for(long long int i=n-1;i>=0;i--){
        auto it = m.find(s[i]);
        if(it!=m.end()){
            next[i]=m[s[i]];
        }
        else{
            next[i]=-2;
        }
        m[s[i]]=i;
        
    }
    vector<vector<long long int>>dp(n,vector<long long int>(n,0));
    for(long long int i=n-1;i>=0;i--){
        for(long long int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=1;
            }
            else if(i+1==j){
                dp[i][j]=2;
            }
            else{
                if(s[i]==s[j]){
                    long long int one = next[i];
                    long long int two = prev[j];
                    if(one==j && two==i){
                        dp[i][j] = op2(dp[i+1][j-1],2,MOD) + 2;
                    }
                    else if(one==two){
                        dp[i][j] = op2(dp[i+1][j-1],2,MOD) + 1;
                        // dp[i][j] = 2*dp[i+1][j-1] + 1;
                    }
                    else{
                        // dp[i][j] = op3(op2(dp[i+1][j-1],2,MOD),dp[one+1][two-1],MOD);
                        dp[i][j] = (2*dp[i+1][j-1]%MOD - dp[one+1][two-1]%MOD)%MOD;
                    }
                }
                else{
                    dp[i][j] =op3(op1(dp[i][j-1],dp[i+1][j],MOD),dp[i+1][j-1],MOD);
                }
            }
        }
    }
        return (dp[0][n-1]+MOD)%MOD;
    }
};