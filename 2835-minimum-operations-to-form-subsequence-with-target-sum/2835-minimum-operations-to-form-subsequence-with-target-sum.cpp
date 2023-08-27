class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int>bit(40);
        long long int sum=0;
        for(auto &i:nums){
            bit[log2(i)]++;
            sum+=i;
        }
        if(sum<target){
            return -1;
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if((target&(1<<i))){
                if(bit[i]){
                    bit[i]--;
                }
                else{
                    int j=i;
                    while(j<32 && bit[j]==0){
                        j++;
                    }
                    bit[j]--;
                    for(int k=i;k<j;k++){
                        bit[k]++;
                    }
                    ans+=(j-i);
                }
            }
            bit[i+1]+=(bit[i]/2);
        }
        return ans;
    }
};