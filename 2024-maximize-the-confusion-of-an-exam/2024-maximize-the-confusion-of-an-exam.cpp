class Solution {
public:
    bool ans(string s,int mid,int k){
        int i=0;
        int j=mid;
        int t=0;
        int f=0;
        for(int k=0;k<mid;k++){
            if(s[k]=='T'){
                t++;
            }
            else{
                f++;
            }
        }
        int req = min(t,f);
        if(req<=k){
            return true;
        }
        while(j<s.size()){
            if(s[i]=='T'){
                t--;
            }
            else{
                f--;
            }
            i++;
            if(s[j]=='T'){
                t++;
            }
            else{
                f++;
            }
            j++;
            int req = min(t,f);
            if(req<=k){
                return true;
            }
        }
        return false;
    }
    int maxConsecutiveAnswers(string s, int k) {
        int sol=s.size();
        int start=1;
        int end=s.size();
        while(start<=end){
            int mid=(start+end)/2;
            if(ans(s,mid,k)){
                sol = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return sol;
        
    }
};