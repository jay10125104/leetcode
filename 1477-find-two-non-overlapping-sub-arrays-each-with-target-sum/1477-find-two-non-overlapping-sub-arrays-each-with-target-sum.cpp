class Solution {
public:
    int minSumOfLengths(vector<int>& v, int target) {
        int n=v.size();
        long long int dp1[n];
        long long int dp2[n];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        map<int,int>m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            dp1[i]=INT_MAX;
            int req = sum-target;
            if(m.find(req)!=m.end())
            dp1[i]=i-m[req];
            if(i-1>=0){
                dp2[i]=min(dp2[i-1],dp2[i]);
            }
            // cout<<dp2[i]<<" "; 
            m[sum]=i;
        }
        sum=0;
        m.clear();
        m[0]=n;
        for(int i=n-1;i>=0;i--){
            sum+=v[i];
            dp2[i]=INT_MAX;
            int req = sum-target;
            if(m.find(req)!=m.end())
            dp2[i]=m[req]-i;
            if(i+1<n){
                dp2[i]=min(dp2[i+1],dp2[i]);
            }
            // cout<<dp2[i]<<" "; 
            m[sum]=i;
        }
       long long int sol=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(dp1[i]!=INT_MAX && dp2[i]!=INT_MAX)
            sol = min(sol,(long long int)(dp1[i]+dp2[i+1]));
        }
        return sol==INT_MAX?(-1):(sol);
    }
};