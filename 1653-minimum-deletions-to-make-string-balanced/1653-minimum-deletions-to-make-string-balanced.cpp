
class Solution {
public:
    
    
    int minimumDeletions(string s) {
       int a=0;
        int n=s.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                a++;
            }
            dp[i]=a;
        }
        int b=0;
        int dp2[n];
        memset(dp2,0,sizeof(dp2));
        for(int i=n-1;i>=0;i--){
            dp2[i]=b;
            if(s[i]=='a'){
                b++;
            }
        }
        int mn = b;
        for(int i=0;i<n;i++){
            mn = min(dp[i]+dp2[i],mn);
        }
        return mn;
        
    }
};