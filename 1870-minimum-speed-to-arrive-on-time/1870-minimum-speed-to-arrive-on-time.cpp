class Solution {
public:
    bool sol(vector<int>&v,int mid,double k){
        double pair=0;
        for(auto i:v){
            pair+=i/(mid);
            if(i%mid){
                pair = pair+1;;
            }
        }
        pair-=v[v.size()-1]/mid;
        if(v[v.size()-1]%mid){
            pair--;
        }
        pair+=(double)((double)v[v.size()-1]/(double)mid);
        // cout<<pair<<" ";
        if(pair<=k){
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& v, double k) {
        long long int start=1;
        long long int end = INT_MAX;
        long long int ans=-1;
        while(start<=end){
            long long int mid = (start+end)/2;
            if(sol(v,mid,k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};