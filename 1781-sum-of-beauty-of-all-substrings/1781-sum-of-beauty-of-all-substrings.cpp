class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for(auto &i:m){
                    mx = max(mx,i.second);
                    mn = min(mn,i.second);
                }
                ans+=(mx-mn);
            }
        }
        return ans;
    }
};