class Solution {
public:
    bool ans(vector<int>&v,int m,int k,long long int mid){
        int count=0;
        int count2=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=mid){
                count++;
            }
            else{
                count=0;
            }
            if(count==k){
                count=0;
                count2++;
            }
            
        }
        return count2>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        long long int low =0;
        long long int high = INT_MAX;
        int sol=-1;
        while(low<=high){
            long long int mid=(low+high)/2;
            if(ans(v,m,k,mid)){
                sol = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return sol;
    }
};