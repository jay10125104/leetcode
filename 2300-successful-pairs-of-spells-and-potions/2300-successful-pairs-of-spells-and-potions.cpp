class Solution {
public:
    vector<int> successfulPairs(vector<int>& v, vector<int>& t, long long k) {
        vector<pair<int,int>>p;
        for(int i=0;i<v.size();i++){
            p.push_back({v[i],i});
        }
        int n=v.size();
        sort(p.begin(),p.end());
        sort(t.begin(),t.end(),greater<int>());
        int j=0;
        vector<int>ans(n);
        for(int i=0;i<v.size();i++){
            int x = p[i].first;
            while(j<t.size() && (1ll * x * 1ll * t[j])>=k){
                j++;
            }
            ans[p[i].second]=j;
        }
        return ans;
    }
};