class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long int sum=0;
        int n=nums.size();
        for(int i=0;i<min(n,2*k);i++){
            sum+=nums[i];
        }
        int i=0;
        int j=2*k;
        int t=k;
        int total = 2*k+1;
        vector<int>ans(n,-1);
        while(j<n){
            sum+=nums[j];
            ans[k]=sum/total;
            sum-=nums[i];
            i++;
            j++;
            k++;
        }
        return ans;
    }
};