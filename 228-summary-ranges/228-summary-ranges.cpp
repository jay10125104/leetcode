class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        
        int one=nums[0];
        vector<string>ans;
        long long int mn=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(((long long int)nums[i]-(long long int)nums[i-1])!=1){
                string mid="";
                mid+=to_string(mn);
                if(nums[i-1]!=mn){
                mid+="->";
                mid+=to_string(nums[i-1]);
                }
                ans.push_back(mid);
                mn=nums[i];
            }
        }
        string mid="";
        mid+=to_string(mn);
        int n=nums.size();
        if(nums[n-1]!=mn){
            mid+="->";
            mid+=to_string(nums[n-1]);
        }
        ans.push_back(mid);
        return ans;
    }
};