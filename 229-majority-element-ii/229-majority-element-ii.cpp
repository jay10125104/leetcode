class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        map<int,int>m;
        for(auto &i:nums){
            m[i]++;
        }
        vector<int>ans;
        for(auto &i:m){
            if(i.second>n){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};