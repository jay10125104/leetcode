class Solution {
public:
    bool ans(string s,int k,long long int mid1){
        string mid = "";
        mid+=s[0];
        long long int count=1;
        int x = stoll(mid);
        if(x>k){
            return false;
        }
        for(int i=1;i<s.size();i++){
            mid+=s[i];
            long long int x = stoll(mid);
            // cout<<mid<<" "<<endl;
            if(x>k){
                mid="";
                mid+=s[i];
                count++;
            }
            x = stoll(mid);
            if(x>k && mid.size()==1){
                return false;
            }
        }
        return count<=mid1;
    }
    int minimumPartition(string s, int k) {
        int sol=-1;
        long long int low=0;
        // cout<<ans(s,k,6);
        long long int high = INT_MAX;
        while(low<=high){
            long long int mid = (low+high)/2;
            if(ans(s,k,mid)){
                high = mid-1;
                sol = mid;
            }
            else{
                low=mid+1;
            }
        }
        return sol;
    }
};