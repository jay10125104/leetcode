class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>left(n,vector<int>(n));
        vector<vector<int>>right(n,vector<int>(n));
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                left[i][j] = count;
                if(nums[i]>nums[j]){
                    count++;
                }
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                right[i][j] = count;
                if(nums[i]<nums[j]){
                    count++;
                }
            }           
        }
        long long int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                if(nums[i]>nums[j]){
                int first = left[j][i];
                int second = right[i][j];
                ans+=(first*second);
                }
            }
        }
        return ans;
        // return -1;
    }
};