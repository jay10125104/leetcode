class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]*i);
            sum+=nums[i];
        }
        int sol = ans;
        // cout<<ans<<" ";
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            ans+=sum;
            ans-=((n)*nums[i]);
            // cout<<ans<<" ";
            sol=max(sol,ans);
        }
        return sol;
    }
};