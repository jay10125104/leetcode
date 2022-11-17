class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j=0;
        // int ans=0;
        int count=0;
        vector<int>v;
        v.push_back(-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                v.push_back(i);
            }
        }
        v.push_back(nums.size());
        int i=1;
        int ans=0;
        while((i+k)<v.size()){
            int prev = v[i]-v[i-1] - 1;
            int next = v[i+k]-v[i+k-1] - 1;
            ans+=prev;
            ans+=next;
            ans++;
            ans+=(prev*next);
            i++;
        }
        return ans;
        return ans;
    }
};