class Solution {
public:
    long long countSubarrays(vector<int>& v, long long k) {
        long long int ans=0;
        queue<long long int>q;
        long long int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            q.push(v[i]);
            while((sum*q.size())>=k && q.size()){
                long long int x = q.front();
                q.pop();
                sum-=x;
            }
            ans+=q.size();
            // cout<<sum<<" "<<ans<<endl;
        }
        return ans;
    }
};