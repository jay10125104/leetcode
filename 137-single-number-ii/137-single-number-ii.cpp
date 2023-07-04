class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=31;i++){
            int count=0;
            int mask = (1ll<<i);
            for(auto &j:nums){
                if(j&mask){
                    count++;
                }
            }
            
            // cout<<count<<" ?"<<mask<<endl;
            if((count%3)==1){
                ans|=mask;
            }
        }
        return ans;
    }
};