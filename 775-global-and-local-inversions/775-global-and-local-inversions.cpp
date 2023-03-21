class Solution {
public:
    // int count2 = 0;
    int t[1000000];
    long long int merge(vector<int>&v,int i,int mid,int j){
        int sz = (j-i+1);
        
        int count=0;
        int idx1=i;
        int idx2=mid+1;
        long long int ans=0;
        while(idx1<=mid && idx2<=j){
            if(v[idx1]>v[idx2]){
                ans+=(mid-idx1+1);
                t[count++]=v[idx2];
                idx2++;
            }
            else{
                t[count++]=v[idx1];
                idx1++;
            }
        }
        while(idx1<=mid){
            t[count++]=v[idx1++];
        }
        while(idx2<=j){
            t[count++]=v[idx2++];
        }
        count=0;
        for(int k=i;k<=j;k++){
            v[k]=t[count++];
        }
        return ans;
    }
    long long int mergesort(vector<int>&nums,int i,int j){
        if(i==j){
            return 0;
        }
        else{
            long long int mid=(i+j)/2;
            long long int left = mergesort(nums,i,mid); 
            long long int right = mergesort(nums,mid+1,j);
            long long int midd = merge(nums,i,mid,j);
            return left+midd+right;
        }
    }
    bool isIdealPermutation(vector<int>& nums) {
        int count1=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count1++;
            }
        }
        
        // cout<<count2<<endl;
        int count2 = mergesort(nums,0,nums.size()-1);
        // cout<<count2<<endl;
        return count1==count2;
    }
};