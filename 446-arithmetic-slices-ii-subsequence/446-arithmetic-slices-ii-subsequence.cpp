class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long int ans=0;
        vector<map<long long int,long long int>>v(nums.size());
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                long long int x = (long long int)((long long int)nums[i]-(long long int)nums[j]);
                ans+=v[j][x];
                v[i][x]+=(1+v[j][x]);
            }
        }
        return ans;
    }
};