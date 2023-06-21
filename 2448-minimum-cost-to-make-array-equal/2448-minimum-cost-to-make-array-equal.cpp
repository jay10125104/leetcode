class Solution {
public:
    long long int ans(vector<int>&v,vector<int>&t,long long int mid){
        long long int mincost=0ll;
        int n=v.size();
        for(int j=0;j<n;j++){
            long long int m = abs(v[j]-mid);
            mincost+=(m*1ll*t[j]);
        }
        return mincost;
    }
    long long minCost(vector<int>& v, vector<int>& t) {
        long long int sol = 1e15;
        long long int low = 0;
        long long int high = 1000000;
        while(low<=high){
            long long int mid=(low+high)/2;
            long long int ans1 = ans(v,t,mid);
            long long int ans2 = ans(v,t,mid+1);
            // cout<<mid<<" "<<ans1<<" "<<ans2<<endl;
            if(ans1<ans2){
                sol = ans1;
                high=mid-1;
            }
            else{
                sol=ans2;
                low=mid+1;
            }
        }
        return sol;
    }
};