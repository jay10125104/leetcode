class Solution {
public:
    bool sol(vector<int>&time,long long int mid,int k){
        long long int trips=0;
        for(auto &i:time){
            trips+=(long long int)(mid/i);
        }
        return trips>=k;
    }
    long long minimumTime(vector<int>& time, int k) {
        long long int low =0;
        int n=time.size();
        sort(time.begin(),time.end());
        long long int high = ((long long int)time[n-1]*(long long int)k);
        long long int ans = -1;
        while(low<=high){
            long long int mid = (low+high)/2;
            // cout<<mid<<endl;
            if(sol(time,mid,k)){
                high = mid-1;
                ans=mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};