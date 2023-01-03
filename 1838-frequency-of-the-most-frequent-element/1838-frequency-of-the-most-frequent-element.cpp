class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int ans=1;
        long long int diff=0;
        while(j<nums.size()){
            long long int mid = nums[j]-nums[j-1];
            diff+=((mid)*(j-i));
            while(diff>k){
                diff-=(nums[j]-nums[i]);
                i++;
            }
            // cout<<diff<<" ";
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};