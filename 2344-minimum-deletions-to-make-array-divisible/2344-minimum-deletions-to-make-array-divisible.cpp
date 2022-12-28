class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& v) {
        map<long long int,int>m;
        for(auto &i:nums){
            m[i]++;
        }
        long long int gcd=v[0];
        for(int i=1;i<v.size();i++){
            gcd = __gcd(gcd,(long long int)v[i]);
        }
        long long int ans=0;
        for(auto &i:m){
            int x = i.first;
            if(gcd%x==0){
                break;
            }
            else{
                ans+=i.second;
            }
        }
        return (ans==nums.size())?(-1):(ans);
    }
};