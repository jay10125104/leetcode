class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        stack<long long int>s;
        long long int ans=0;
        map<long long int,long long int>m;
        for(auto &i:nums){
            int x = i;
            while(s.size()){
                if(s.top()<x){
                    m[s.top()]--;
                    s.pop();
                }
                else{
                    break;
                }
            }
            s.push(x);
            m[x]++;
            ans+=(m[x]);
        }
        return ans;
    }
};