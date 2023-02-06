class Solution {
public:
    bool sol(vector<int>&nums,long long int mid){
        long long int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                k+=(mid-nums[i]);
            }
            else{
                int rid = nums[i]-mid;
                if(rid>k){
                    return false;
                }
                else{
                    k-=rid;
                }
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low =0;
        int high = INT_MAX;
        int ans=0;
        while(low<=high){
            long long int mid = (low) + (high-low)/2;
            if(sol(nums,mid)){
                high =  mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};