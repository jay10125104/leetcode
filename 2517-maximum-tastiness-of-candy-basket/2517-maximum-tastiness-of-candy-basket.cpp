class Solution {
public:
    int maximumTastiness(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        long long int low=0;
        long long int high=INT_MAX;
        int sol=0;
        while(low<=high){
            long long int mid = (low+high)/2;
            int count=1;
            int prev = v[0];
            for(int i=0;i<v.size();i++){
            if((v[i]-prev)>=mid){
                count++;
                prev =v[i];
            }
        }
            if(count>=k){
                sol = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return sol;
    }
};