class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        long long int ans=0;
        long long int pro=1;
        
        for(int i=0;i<nums.size();i++){
            pro*=nums[i];
            while(i>=j && pro>=k){
                pro/=nums[j];
                j++;
            }
            ans+=(i-j+1);
            
        }
        return ans;
    }
};