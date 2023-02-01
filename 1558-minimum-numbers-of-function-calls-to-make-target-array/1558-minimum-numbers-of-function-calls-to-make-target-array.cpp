class Solution {
public:
    int ans(vector<int>&nums){
        int count=0;
        int zero=0;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]%2){
                count++;
                nums[i]--;
            }
            if(nums[i]==0){
                zero++;
                continue;
            }
            flag=1;
            nums[i] = nums[i]/2;
        }
        // cout<<count<<" "<<zero<<" "<<flag<<endl;
        if(zero==nums.size()){
            return count;
        }
        else{
            return flag+count+ans(nums);
        }
    }
    int minOperations(vector<int>& nums) {
        return ans(nums);
    }
};