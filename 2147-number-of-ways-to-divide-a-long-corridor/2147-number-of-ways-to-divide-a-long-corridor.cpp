class Solution {
public:
    int numberOfWays(string s) {
        int count=0;
        s.push_back('S');
        s.push_back('S');
        vector<int>mid;
        int t=0;
        for(auto &i:s){
            if(count%2==0)
            t+=(i=='P');
            count+=(i=='S');
            if(i=='S' && count%2==0){
                mid.push_back(t);
                t=0;
            }
        
        }
        // cout<<count<<" ";
        if(count%2 || count==2){
            return 0;
        }
        long long int ans=1;
        long long int mod=1000000007;
        for(int i=1;i<mid.size()-1;i++){
            
            ans = (ans%mod * (mid[i]+1)%mod)%mod;
        }
        return (ans+mod)%mod;
        
    }
};