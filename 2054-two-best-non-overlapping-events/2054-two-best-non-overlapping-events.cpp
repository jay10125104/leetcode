bool cmp(vector<int>&v,vector<int>&t){
    return v[1]<t[1];
}
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        int ans=0;
        int n=v.size();
        int dp[n];
        sort(v.begin(),v.end(),cmp);
        memset(dp,0,sizeof(dp));
        dp[0]=v[0][2];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],v[i][2]);
        }
        for(int i=0;i<n;i++){
            int start = 0;
            int end=i-1;
            int sol=0;
            while(start<=end){
                int mid = (start+end)/2;
                if(v[mid][1]<v[i][0]){
                    sol = dp[mid];
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            ans = max(ans,sol+v[i][2]);
        }
        return ans;
    }
};