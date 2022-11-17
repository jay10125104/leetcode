class Solution {
public:
    vector<int> sol(vector<int>&v,int a){
       long long int sum=0;
        vector<int>ans;
       int dp1[v.size()];
       int b=a;
       long long int dp[v.size()];
       long long int dp2[v.size()];
       memset(dp,0,sizeof(dp));
       memset(dp1,-1,sizeof(dp1));
       memset(dp2,0,sizeof(dp2));
       // int sum=0;
       for(int i=0;i<a;i++){
              sum+=v[i];
       }
       int n=v.size();
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
       dp1[v.size()-b]=sum;
       j=v.size()-b-1;
       i=v.size()-1;
       while(j<v.size()){
              sum+=v[j];
              sum-=v[i];
              dp1[j] = sum;
              dp2[j] = max(sum,dp2[j+1]);
              j--;
              i--;
       }
       // printv(dp2);
       sum=0;
       count=0;
       long long int mx =0;
       for(int i=n-a-1;i>=0;i--){
              sum+=v[i];
              count++;
              if(count==a){
                     break;
              }
       }
       i = n-a-1;
       j = n-2*a-1;
       int idx2 = j+1;
       mx = sum + dp2[i+1] + dp[j];
       while(j!=(a-1)){
              sum+=v[j];
              sum-=v[i];
              i--;
              j--;
              if(mx<=(sum+dp2[i+1]+dp[j])){
                     idx2 = j+1;
              }
              mx = max(mx,sum+dp2[i+1]+dp[j]);
       }
       int mx1 = INT_MIN;
       int idx1 = 0;
       for(int i=0;i<idx2;i++){
              if(dp[i]>mx1){
                     idx1 = i;
                     mx1 = dp[i];
              }
       }
       // printv(dp2);
       // printv(dp1);
       // cout<<mx<<" "<<idx1-a+1<<" "<<idx2<<" ";
       ans.push_back(idx1-a+1);
       ans.push_back(idx2);
        mx1 = INT_MIN;
       for(int i=idx2+a;i<n;i++){
              if(dp1[i]>mx1){
                     idx1 = i;
                     mx1 = dp1[i];
              }
       }
       ans.push_back(idx1);
       return ans;
}
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        return sol(nums,k);
    }
};