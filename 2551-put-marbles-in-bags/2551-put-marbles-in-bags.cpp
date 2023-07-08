class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        int n=v.size();
        vector<long long int>t;
        long long int ans1=v[0]+v[n-1];
        long long int ans2=v[0]+v[n-1];
        for(int i=1;i<n;i++){
            t.push_back(v[i]+v[i-1]);
        }
        sort(t.begin(),t.end());
        for(int i=1;i<k;i++){
            ans1+=t[i-1];
        }
        for(int i=1;i<k;i++){
            ans2+=t[(int)t.size()-i];
        }
        return abs(ans1-ans2);
    }
};