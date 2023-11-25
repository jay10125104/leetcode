class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int size=nums.size();
        vector<int>pre(size,0);
        int sum=nums[0];
        for(int i=1;i<size;i++){
            pre[i] = pre[i-1]+nums[i-1];
            sum=sum+nums[i];
            
        }
        vector<int>post(size,0);
        
        for(int i=0;i<size;i++){
            post[i] = sum-nums[i];
            sum=sum-nums[i];
        }
        vector<int>ans;
        for(int i=0;i<size;i++){
            int mid = (post[i] - (nums[i]*(size-1-i))) + (nums[i]*i - pre[i]);
            ans.push_back(mid);
        }
        return ans;
    }
};