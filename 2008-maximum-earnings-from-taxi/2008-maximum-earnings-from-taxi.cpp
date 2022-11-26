class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
        vector<pair<long long int,pair<long long int,long long int>>>v;
        n=ride.size();
        for(int i=0;i<n;i++){
            v.push_back({ride[i][1],{ride[i][0],ride[i][2]}});
        }
        sort(v.begin(),v.end());
        long long int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0] = v[0].second.second + (v[0].first-v[0].second.first);
        for(int i=1;i<n;i++){
            int low = 0;
            int high = i-1;
            int idx=-1;
            long long int start = v[i].second.first;
            while(low<=high){
                long long int mid = (low+high)/2;
                if(v[mid].first<=start){
                    low = mid+1;
                    idx=mid;
                }
                else{
                    high = mid-1;
                }
            }
            if(idx==-1){
                dp[i] = max(v[i].second.second + (v[i].first-v[i].second.first),dp[i-1]);
            }
            else{
                dp[i] = max({dp[idx]+v[i].second.second + (v[i].first-v[i].second.first),dp[i-1]});
            }
        }
        return dp[n-1];
    }
};