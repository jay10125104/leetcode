class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=0;
        int count=0;
        char dummy = '*'; 
        for(int i=0;i<s.size();i++){
            if(dummy=='*'){
                dummy = s[i];
                count=1;
            }
            else if(dummy==(s[i]-1)){
                dummy = s[i];
                count++;
            }
            else{
                count=1;
                dummy = s[i];
            }
            ans = max(ans,count);
        }
    return ans;
    }
    
};