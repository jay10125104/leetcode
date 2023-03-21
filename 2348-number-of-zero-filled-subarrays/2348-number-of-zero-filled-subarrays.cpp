class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int sol=0;
        long long int ans=0;
        for(auto i:nums){
            if(i==0){
                ans++;
            }
            else{
                sol+=((ans)*(ans+1))/2;
                ans=0;
            }
        }
        if(ans){
                sol+=((ans)*(ans+1))/2;   
        }
        return sol;
    }
};