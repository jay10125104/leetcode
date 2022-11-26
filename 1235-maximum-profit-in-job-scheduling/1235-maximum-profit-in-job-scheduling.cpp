class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>v;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            v.push_back({endTime[i],{startTime[i],profit[i]}});
        }
        sort(v.begin(),v.end());
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0] = v[0].second.second;
        for(int i=1;i<n;i++){
            int low = 0;
            int high = i-1;
            int idx=-1;
            int start = v[i].second.first;
            while(low<=high){
                int mid = (low+high)/2;
                if(v[mid].first<=start){
                    low = mid+1;
                    idx=mid;
                }
                else{
                    high = mid-1;
                }
            }
            if(idx==-1){
                dp[i] = max(v[i].second.second,dp[i-1]);
            }
            else{
                dp[i] = max({dp[idx]+v[i].second.second,dp[i-1]});
            }
        }
        return dp[n-1];
    }
};