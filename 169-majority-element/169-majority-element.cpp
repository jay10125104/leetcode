class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int prev=nums[0];
        for(auto &i:nums){
            if(count==0){
                prev=i;
            }
            if(i==prev){
                count++;
            }
            else{
                count--;
            }
            
        }
        return prev;
    }
};