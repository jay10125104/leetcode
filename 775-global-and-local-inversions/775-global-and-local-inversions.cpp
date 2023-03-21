class Solution {
public:
    long long int global = 0;
    long long int temp[1000000];
    void merge(vector<int> &nums,int l,int mid,int r){
        long long int i = l;
        long long int j = mid+1;
        long long int k = l;
        
        while(i<=mid and j <= r){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
                global+=(mid-i+1);
            }
        }
        
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        
        while(j <= r){
            temp[k++] = nums[j++];
        }
        
        for(long long int i = l; i <= r;i++){
            nums[i] = temp[i];
        }
    }
    
    void Mergesort(vector<int>&nums,int l,int r){
        if(l>=r) return;
        int mid = (l+r)/2;
        
        Mergesort(nums,l,mid);
        Mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        int local = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1])
                local++;
        }
        Mergesort(nums,0,nums.size()-1);
        
        return global == local ? 1 : 0;
    }
};