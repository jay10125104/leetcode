class Solution {
public:
int partition(vector<int>&v,int low,int high){
    int counter=low;
    int pivot = v[high];
    for(int i=low;i<high;i++){
        if(v[i]<pivot){
            swap(v[counter++],v[i]);
        }
    }
    swap(v[counter],v[high]);
    return counter;
}
int quickselect(vector<int>&v,int low,int high,int k){
    if(low==high){
        return v[low];
    }
    else{
        int mid= partition(v,low,high);
        if(mid==k){
            return v[mid];
        }
        else if(mid>k){
            return quickselect(v,low,mid-1,k);
        }
        else{
            return quickselect(v,mid+1,high,k);
        }
    }
}
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,0,nums.size()-1,nums.size()-k);
    }
};