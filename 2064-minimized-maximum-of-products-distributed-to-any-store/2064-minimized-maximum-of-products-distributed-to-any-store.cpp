class Solution {
public:
    bool ans(vector<int>&v,int mid,int n){
        int t =0 ;
        for(auto i:v){
            t+=(i/mid);
            if(i%mid){
                t++;
            }
        }
        return t<=n;
    }
    int minimizedMaximum(int n, vector<int>& v) {
        int start=1;
        int end=1e9;
        int sol = 0;
        while(start<=end){
            int mid = (start+end)/2;
            if(ans(v,mid,n)){
                sol = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            // cout<<mid<<" "<<start<<" "<<end<<endl;
        }
        return sol;
    }
};