class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd=numsDivide[0];
        for(auto &i:numsDivide){
            gcd = __gcd(gcd,i);
        }
        map<int,int>m;
        for(auto num:nums){
            m[num]++;
        }
        int ans=0;
        for(auto &i:m){
            int x = i.first;
            int y = i.second;
            if(gcd%x!=0){
                ans+=y;
            }
            else{
                break;
            }
        }
        return ((ans==nums.size())?(-1):(ans));
    }
};