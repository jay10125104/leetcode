class Solution {
public:
    int maxCoins(vector<int>& piles) {
       sort(piles.begin(),piles.end());
        int n=piles.size();
        int ans=0;
        // for(auto &i:piles){
        //     cout<<i<<" ";
        // }

        for(int i=n-2;i>=n/3;i-=2){
            // cout<<piles[i];
            ans+=piles[i];
        }
        return ans;
    }
};