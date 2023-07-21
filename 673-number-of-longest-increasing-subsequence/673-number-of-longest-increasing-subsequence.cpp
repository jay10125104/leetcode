class Solution {
public:
    
    int findNumberOfLIS(vector<int>& v) {
        int n=v.size();
        int dp[n];
        int count[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
            count[i]=1;
        }
        int len=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=i-1;j>=0;j--){
                if(v[i]>v[j] && (dp[i]<=(dp[j]+1))){
                    if(dp[i]==(dp[j]+1)){
                        count[i]+=count[j];
                    }
                    else{
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                }
                
            }
            len = max(len,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==len){
                ans+=count[i];
            }
        }
        return ans;
    }
};