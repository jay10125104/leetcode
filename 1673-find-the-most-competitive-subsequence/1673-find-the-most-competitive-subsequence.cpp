class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            while(s.size() && s.top()>nums[i] && ((k-s.size())<=(nums.size()-i-1))){
                s.pop();
            }
            if(s.size()<k)
            s.push(nums[i]);
        }
        vector<int>ans;
        while(s.size()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};