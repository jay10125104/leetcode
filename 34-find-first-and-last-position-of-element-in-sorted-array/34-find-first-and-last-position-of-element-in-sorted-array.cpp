class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(),nums.end(),target);
        
        if(it1==nums.end() || *it1!=target){
            return {-1,-1};
        }
        cout<<"df";
        vector<int>ans;
        ans.push_back(it1-nums.begin());
        auto it2 = upper_bound(nums.begin(),nums.end(),target);
        ans.push_back((it2-nums.begin())-1);
        return ans;
        
    }
};