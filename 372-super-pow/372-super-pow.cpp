class Solution {
public:
    int mod = 1337;
    long long int ans(long long int x,long long int y){
        long long int sol = 1;
        // cout<<y<<" ";
        while(y){
            if(y&1){
            sol = (sol*x)%mod;
            }
            x = (x*x)%mod;
            y=y/2;
        }
        // cout<<x<<" "<<" "<<sol<<endl;
        return sol;
    }
    
    int superPow(int a, vector<int>& b) {
        // reverse(b.begin(),b.end());
        long long int sol=1;
        for(int i=0;i<b.size();i++){
            long long int x = b[i];
            sol = (ans(sol,(long long int)10)%mod * (ans((long long int)a,x))%mod)%mod;
            // cout<<sol<<" ";
        }
        return sol;
    }
};