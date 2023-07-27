class Solution {
public:
    
    bool ans(vector<int>&v,long double n,long double mid){
        long double k=0;
        for(auto &i:v){
            if(i<mid){
                k+=i;
            }
            else{
                k+=mid;
            }
            if(k>=(n*mid)){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& v) {
        long low=0;
        long sol=0;
        long high = 1e15;
        while(low<=high){
            long mid = (low+high)/2;
            if(ans(v,n,mid)){
                sol=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return sol;
    }
};