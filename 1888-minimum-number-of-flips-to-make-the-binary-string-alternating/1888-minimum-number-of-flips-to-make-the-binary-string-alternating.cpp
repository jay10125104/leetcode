class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int dp1[n];
        int dp2[n];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        int req=1;
        for(int i=0;i<n;i++){
            int x = s[i]-'0';
            if(x!=req){
                dp1[i]=1;
            }
            if((i-1)>=0){
                dp1[i]+=dp1[i-1];
            }
            // cout<<dp1[i]<<" ";
            req = !req;
        }
        
        // cout<<endl;
        req = 0;
        for(int i=0;i<n;i++){
            int x = s[i]-'0';
            if(x!=req){
                dp2[i]=1;
            }
            if((i-1)>=0){
                dp2[i]+=dp2[i-1];
            }
            // cout<<dp2[i]<<" ";
            req = !req;
        }
        // cout<<endl;
        int ans = min(dp1[n-1],dp2[n-1]);
        int len=n;
        for(int i=0;i<n;i++){
            int firstreq = dp1[n-1];
            if((i-1)>=0){
                firstreq-=dp1[i-1];
                if(n%2){
                    firstreq+=dp2[i-1];
                }
                else{
                    firstreq+=dp1[i-1];
                }
            }
            ans = min(ans,firstreq);
            firstreq = dp2[n-1];
            if((i-1)>=0){
                firstreq-=dp2[i-1];
                if(n%2){
                    firstreq+=dp1[i-1];
                }
                else{
                    firstreq+=dp2[i-1];
                }
            }
            ans = min(ans,firstreq);
            
            // len--;
        }
        return ans;
    }
};