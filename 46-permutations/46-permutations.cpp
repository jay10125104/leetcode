class Solution {
public:
    void ans(vector<vector<int>>&sol,vector<int>nums,int idx){
        if(idx>=nums.size()){
            sol.push_back(nums);
            return;
        }
        else{
            for(int i=idx;i<nums.size();i++){
                swap(nums[i],nums[idx]);
                ans(sol,nums,idx+1);
                swap(nums[i],nums[idx]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>sol;
        ans(sol,nums,0);
        return sol;
    }
};