class Solution {
public:
    int sol(string s){
        int n=s.size();
        if(n==0){
            return 0;
        }
        int dp[n][n];
        int len=0;
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if((i+1)==j){
                    dp[i][j]=((s[i]==s[j])?(2):(1));
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                    }
                }
                len = max(len,dp[i][j]);
            }
        }
        return len;
    }
    int maxProduct(string s) {
        int n=s.size();
        int x = pow(2,n);
        int ans=0;
        for(int i=1;i<=x;i++){
            int t = i;
            string one="";
            string two="";
            for(int j=0;j<n;j++){
                if(t&(1<<j)){
                    one+=s[j];
                }
                else{
                    two+=s[j];
                }
            }
            // if(one=="tottot")
            // cout<<one<<" "<<two<<" "<<sol(one)<<" "<<sol(two)<<endl;
            ans = max({ans,sol(one)*sol(two)});
        }
        return ans;
    }
};
// "xcqcnx"
// tottot

// xtctx
// xtcctx