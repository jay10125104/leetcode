class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto x = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(x<nums.size() && nums[x]==target){
            return x;
        }
        else{
            return -1;
        }
    }
};