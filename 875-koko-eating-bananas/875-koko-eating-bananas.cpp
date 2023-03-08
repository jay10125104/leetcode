class Solution {
public:
    bool sol(vector<int>&v,int h,long long int mid){
        long long int sum=0;
        for(auto i:v){
            sum+=(i/mid);
            if(i%mid){
                sum++;
            }
        }
        if(sum<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& v, int h) {
        long long int start =1 ;
        long long int end=INT_MAX;
        long long int ans = INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            if(sol(v,h,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start= mid+1;
            }
        }
        return ans;
    }
};