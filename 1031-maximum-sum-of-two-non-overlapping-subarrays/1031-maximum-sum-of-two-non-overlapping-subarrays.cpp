class Solution {
public:
    long long int ans(vector<int>&v,int a,int b){
       long long int sum=0;
       long long int dp[v.size()];
       long long int dp2[v.size()];
       memset(dp,0,sizeof(dp));
       memset(dp2,0,sizeof(dp2));
       // int sum=0;
       for(int i=0;i<a;i++){
              sum+=v[i];
       }
       dp[a-1] = sum;
       int j=a,i=0;
       while(j<v.size()){
              sum+=v[j];
              sum-=v[i];
              dp[j] = max(sum,dp[j-1]);
              j++;
              i++;
       }
       // printv(dp);
       int count=0;
       sum=0;
       for(int i=v.size()-1;i>=0;i--){
              sum+=v[i];
              count++;
              if(count==b){
                     break;
              }
       }
       dp2[v.size()-b] = sum;
       j=v.size()-b-1;
       i=v.size()-1;
       while(j<v.size()){
              sum+=v[j];
              sum-=v[i];
              dp2[j] = max(sum,dp2[j+1]);
              j--;
              i--;
       }
       // printv(dp2);
       long long int mx =0;
       for(int i=a-1;i<v.size()-b;i++){
              mx = max(mx,dp[i]+dp2[i+1]);
       }
       return mx;
}
    int maxSumTwoNoOverlap(vector<int>& nums, int a, int b) {
        return max(ans(nums,a,b),ans(nums,b,a));
    }
};