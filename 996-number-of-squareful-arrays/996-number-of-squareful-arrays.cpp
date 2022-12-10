class Solution {
public:
    int ans(vector<int>&nums,int prev,int mask){
        int t = __builtin_popcount(mask);
        if(t==nums.size()){
            return 1;
        }
        else{
            int sol=0;
            map<int,int>m;
            for(int i=0;i<nums.size();i++){
                if((mask&(1<<i))==0 && m[nums[i]]==0){
                    t = prev+nums[i];
                    int mid=sqrt(t);
                    if((mid*mid)==t){
                      sol+=(ans(nums,nums[i],mask|(1<<i)));  
                    }
                    m[nums[i]]++;
                }
                
            }
            return sol;
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        map<int,int>m;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0){
                sol+=ans(nums,nums[i],(1<<i));
            }
            m[nums[i]]++;
        }
        return sol;
    }
};