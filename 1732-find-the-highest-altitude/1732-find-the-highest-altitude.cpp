class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0;
        int ans=0;
        for(auto &i:gain){
            mx+=i;
            ans=max(ans,mx);
        }
        return ans;
    }
};