class Solution {
public:
    int maxProfit(vector<int>& v) {
        int mx=0;
        int ans=0;
        for(int j=v.size()-1;j>=0;j--){
            int i=v[j];
            ans = max(ans,mx-i);
            mx = max(mx,i);
            // cout<<ans<<" "<<mx<<endl;
        }
        return ans;
    }
};