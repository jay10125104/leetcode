class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>v(k,0);
        v[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem = (sum%k + k )%k;
            if(v[rem]){
                count+=v[rem];
                v[rem]++;
            }
            else{
                v[rem]=1;
            }
        }
        return count;
        
    }
};