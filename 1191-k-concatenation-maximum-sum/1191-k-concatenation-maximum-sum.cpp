class Solution {
public:
    long long int ans(vector<int>v){
        long long int n=v.size();
        long long int sum=0;
        long long int ans=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(sum<0){
                sum = 0;
            }
            else{
                ans = max(ans,sum);
            }
        }
        return ans;
    }
    int kConcatenationMaxSum(vector<int>&v, int k) {
        long long int sum=0;
        for(auto i:v){
            sum+=i;
        }
        if(k==1){
            return ans(v)<0?0:ans(v);
        }
        vector<int>dup=v;
        set<int>s;
            for(auto i:v){
                dup.push_back(i);
                s.insert(i);
                
            }
        if(sum<0){
            long long int sol =  ans(dup);
            if(sol<0){
                return 0;
            }
            else{
                return sol;
            }
        }
        else{
            int mod=1000000007;
            long long int t=k-2;
            long long int sol=0;
            while(t--){
                sol = (sol%mod+sum%mod)%mod;  
            }
            return (ans(dup)%mod + sol%mod)%mod;
            // return sol;
        }
    }
};