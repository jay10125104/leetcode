#define ll long long int
ll op1(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll op2(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll op3(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        stack<pair<int,int>>s;
        int n=v.size();
        ll ans=0;
        s.push({INT_MIN,n});
        long long int prev[n];
        long long int next[n];
        memset(prev,0,sizeof(prev));
        memset(next,0,sizeof(next));
        for(int i=n-1;i>=0;i--){
            while(s.size() && s.top().first>v[i]){
                s.pop();
            }
            next[i] = (s.top().second-i-1);
            s.push({v[i],i});
        }
        while(s.size()){
            s.pop();
        }
        s.push({INT_MIN,-1});
        int mod = 1000000007;
        for(int i=0;i<n;i++){
            while(s.size() && s.top().first>=v[i]){
                s.pop();
            }
            prev[i] = (abs(s.top().second-i)-1);
            s.push({v[i],i});
            // cout<<prev[i]<<" ";
            ans+=(long long int)(prev[i]*next[i]+1)*v[i];
            ans+=(long long int)(prev[i]+next[i])*v[i];
        }
        return (ans+mod)%mod;
    }
};