class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>>q;
        for(int i=0;i<nums1.size();i++){
            q.push({-1*(nums2[0]+nums1[i]),i,0});
            // cout<<nums2[0]
        }
        vector<vector<int>>ans;
        while(q.size() && k){
            auto it = q.top();
            q.pop();
            k--;
            ans.push_back({nums1[it[1]],nums2[it[2]]});
            int next_idx = it[2]+1;
            if(next_idx<nums2.size()){
                q.push({-1*(nums2[next_idx]+nums1[it[1]]),it[1],next_idx});
            }
        }
        return ans;
    }
};