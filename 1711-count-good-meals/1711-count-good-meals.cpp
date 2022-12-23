class Solution {
public:
    int countPairs(vector<int>& v) {
        sort(v.begin(),v.end());
        map<long long int,long long int>m;
        for(auto &i:v){
            m[i]++;
        }
        long long int mod = 1000000007;
        long long int ans=0;
        for(auto &i:m){
            long long int x = i.first;
            for(int j=0;j<=21;j++){
                long long int t = pow(2,j);
                long long int req = t-x;
                if(req>=0 && req>=i.first){
                    if(i.first==req){
                        ans = (ans%mod+(((i.second)*(i.second-1))/2)%mod)%mod;
                        
                    }
                    else{
                        if(m.find(req)!=m.end()){
                            long long int mid = m[req];
                            ans = (ans%mod + (mid*i.second)%mod)%mod;
                        }
                        
                    }
                    
                }
                
            }
        }
        return ans;
    }
};