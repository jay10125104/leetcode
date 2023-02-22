bool cmp(vector<int>&v,vector<int>&t){
    return v[1]<t[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int k) {
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            int mn = min(v[i][0],k);
            k-=mn;
            ans+=(mn*v[i][1]);
        }
        return ans;
    }
};