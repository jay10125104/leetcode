class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size()+1;
        vector<int>ans(n);
        for(auto i:nums){
            ans[i]++;
        }
        vector<int>sol;
        for(int i=1;i<=nums.size();i++){
            if(ans[i]==2){
                sol.push_back(i);
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(ans[i]==0){
                sol.push_back(i);
            }
        }
        return sol;
        
    }
};