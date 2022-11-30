class Solution {
public:
        int dp[31][300001];
    
    bool check(int count,int sum,int idx,vector<int>&v){
        if(sum<0 || dp[idx][sum]==0){
            return false;
        }
        if(sum==0 && idx==0){
            return count==0;
        }
        else if(idx==0){
            return false;
        }
        else{
            int ans=false;
            if(dp[idx-1][sum]){
                ans = check(count,sum,idx-1,v);
            }
            int x = v[idx-1];
            ans = ans|check(count-1,sum-x,idx-1,v);
            return ans;
        }
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }
        int n=nums.size();
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                
                
                    int t = nums[i-1];
                    dp[i][j] = dp[i-1][j];
                    if((j-t)>=0){
                        dp[i][j]=dp[i][j]|dp[i-1][j-t];
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=1;i<nums.size();i++){
            int x = (sum*i);
            if((x%n)==0){
                int sum1 = x/n;
                // cout<<sum1<<" "<<i<<endl;
                if(dp[n][sum1]==1 && check(i,sum1,n,nums)){
                    return true;
                }
            }
        }
        return false;
    }
};