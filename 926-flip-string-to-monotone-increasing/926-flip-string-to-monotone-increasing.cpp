class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int one[n];
        int two[n];
        memset(one,0,sizeof(one));
        memset(two,0,sizeof(two));
        int mid=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                mid++;
            }
            one[i]=mid;
            // cout<<mid<<" ";
        }
        mid=0;
        // cout<<endl;
        for(int i=s.size()-1;i>=0;i--){
            
            two[i] = mid;
            // cout<<mid<<" ";
            
            if(s[i]=='0'){
                mid++;
            }
        }
        int ans = mid;
        for(int i=0;i<n;i++){
            ans = min(two[i]+one[i],ans);
        }
        return ans;
        
    }
};