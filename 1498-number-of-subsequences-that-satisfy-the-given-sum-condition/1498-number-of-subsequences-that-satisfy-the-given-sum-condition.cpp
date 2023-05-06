class Solution {
public:
int mod=1e9+7;
int dp[100001];
void func(){
    // long long int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=100000;i++){
        dp[i] = ((dp[i-1]%mod)*(2))%mod;
    }
}
int power2(int n){
    return dp[n]%mod;
}
    int numSubseq(vector<int>& v, int target) {
        func();
        long long int ans=0;
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<n;i++){
            int sol=-1;
            int low=i;
            int high=n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if((v[i]+v[mid])<=target){
                    low=mid+1;
                    sol=mid;
                }
                else{
                    high=mid-1;
                }
            }
            if(sol!=-1){
                int count = sol-i;
                int middle = power2(count);
                ans = ((ans%mod) + (middle%mod))%mod;
            }
        }
        return ans;
    }
};