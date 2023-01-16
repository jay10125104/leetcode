class Solution {
public:
    int numSub(string s) {
        int ans=0;
        int temp=0;
        int mod=1000000007;
        s+='0';
        for(auto &i:s){
            if(i=='1'){
                temp++;
            }
            else{
                temp=0;
            }
            ans = (ans%mod+temp%mod)%mod;
        }
        return ans;
    }
};