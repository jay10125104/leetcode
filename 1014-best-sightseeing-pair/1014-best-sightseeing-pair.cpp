class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size();
        int ans=0;
        int mx = v[v.size()-1] - (n-1);
        for(int i=n-2;i>=0;i--){
            ans=max(ans,i+v[i]+mx);
            mx = max(mx,v[i]-i);
        }
        return ans;
    }
};