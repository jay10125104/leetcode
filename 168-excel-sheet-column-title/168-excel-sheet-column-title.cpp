class Solution {
public:
    string convertToTitle(int n) {
        
    string ans = "";
       while(n>0){
           int digit = n%26;
           if(digit==0){
ans =ans+'Z';
n=n/26;
n=n-1;
           }
           else{
               char digit = n%26 -1 + 65;
               ans = ans +digit;
               n = n/26;
           }

       }
       reverse(ans.begin(),ans.end());
       return ans;

    }
};