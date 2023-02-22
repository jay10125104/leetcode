class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=0;
        int sum1=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            v.push_back(nums[i]);
            if(sum1>(sum-sum1)){
                return v;
            }
        }
        return {};
        
    }
};