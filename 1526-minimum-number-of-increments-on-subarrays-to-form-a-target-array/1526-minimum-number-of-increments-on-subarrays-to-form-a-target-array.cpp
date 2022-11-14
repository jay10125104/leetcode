class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int>s;
        int ans = target[0];
        for(int i=1;i<target.size();i++){
            ans+=max(0,target[i]-target[i-1]);
            // cout<<ans<<" ";
        }
        return ans;
    }
};