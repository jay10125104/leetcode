class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                m[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto &i:m){
            int k = i.second;
            ans+=(((i.second*(i.second-1)))/2)*8;
        }
        return ans;
    }
};