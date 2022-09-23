class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int sol=0;
        for(auto i:s){
            if(i=='R'){
                ans++;
            }
            else{
                ans--;
            }
            if(ans==0){
                sol++;
            }
        }
        return sol;
    }
};