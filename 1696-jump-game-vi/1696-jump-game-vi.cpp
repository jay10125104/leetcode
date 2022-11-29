class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        q.push({nums[0],0});
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            while(q.size() && ((q.top().second+k)<i)){
                q.pop();
            }
            ans = (q.top().first)+nums[i];
            // cout<<ans<<" "<<q.top().first<<endl;  
            q.push({ans,i});
        }
        return ans;
    }
};