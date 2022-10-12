class Solution {
public:
    bool sol(vector<int>&nums,int mid,int &flag){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=mid){
                count++;
            }
        }
        flag=count;
        return count>=mid;
    
    }
    int specialArray(vector<int>& nums) {
        int ans=-1;
        int low = 1;
        int high = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            int flag=0;
            if(sol(nums,mid,flag)){
                if(flag==mid)
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};