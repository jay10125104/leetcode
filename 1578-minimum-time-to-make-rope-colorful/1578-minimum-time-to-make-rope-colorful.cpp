class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int mx = v[0];
        int ans = 0;
        int sum=v[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                mx = max(v[i],mx);
                sum+=v[i];
            }
            else{
                ans+=(sum-mx);
                mx=v[i];
                sum=v[i];
            }
            
        }
        ans+=(sum-mx);
        return ans;
    }
};