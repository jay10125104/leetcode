class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>mn(nums.size());
        mn[0] = nums[0];
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            mn[i] = min(mn[i-1],nums[i]);
        }
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size() && s.top()<=mn[i]){
                s.pop();
            }
            if(s.size() && s.top()<nums[i]){
                return true;
            }
            s.push(nums[i]);
        }
        return false;
        
    }
};