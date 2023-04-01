class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        long long int dp[n+1];
        int mod=1000000007;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++){
            char x = s[i-1];
            if(x>='1' && x<='9'){
                dp[i]+=dp[i-1];
                if((i-2)>=0){
                    char y = s[i-2];
                    if(y=='*'){
                        if(x>='1' && x<='6'){
                            dp[i]+=(dp[i-2]*2);
                        }
                        else{
                            dp[i]+=dp[i-2];
                        }
                    }
                    else{
                        int total = (y-'0')*10 + (x-'0');
                        if(total>=10 && total<=26){
                            dp[i]+=dp[i-2];
                        }
                    }
                }
            }
            else if(x=='0'){
                if((i-2)>=0){
                    char y = s[i-2];
                    if(y=='*'){
                        dp[i]+=(dp[i-2]*2);
                    }
                    else{
                        if(y=='1' || y=='2'){
                            dp[i]+=dp[i-2];
                        }
                    }
                }
            }
            else{
                // cout<<i<<"*"<<endl;
                dp[i]+=(dp[i-1]*9);
                if(i!=1){
                    // continue;
                
                char y = s[i-2];
                if(y=='*'){
                    dp[i]+=dp[i-2]*15;
                }
                else if(y=='1'){
                    dp[i]+=dp[i-2]*9;
                }
                else if(y=='2'){
                    dp[i]+=dp[i-2]*6;
                }
                }
            }
                dp[i]%=mod;
            // cout<<dp[i]<<" "; 
        }
        // cout<<endl;
        return (dp[n]+mod)%mod;
    }
};