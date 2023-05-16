class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long int prev[n];
        long long int suff[n];
        int x=0;
        for(int i=0;i<nums.size();i++){
            prev[i]=x;
            x|=nums[i];
        }
        x=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=x;
            x|=nums[i];
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int mask = pow(2,k)*1ll*nums[i];
            ans=max(ans,prev[i]|suff[i]|mask);
        }
        return ans;
    }
};