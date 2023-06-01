class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int pref=1;
        int suff=1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(pref==0){
                pref=1;
            }
            if(!suff){
                suff=!suff;
            }
            pref*=nums[i];
            suff*=nums[n-i-1];
            ans=max({ans,pref,suff});
        }
        return ans;
        
    }
};