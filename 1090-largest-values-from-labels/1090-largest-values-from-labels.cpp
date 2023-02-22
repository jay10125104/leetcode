bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.first>b.first;
}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int t, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<values.size();i++){
            v.push_back({values[i],labels[i]});
        }
        int ans=0;
        sort(v.begin(),v.end(),cmp);
        map<int,int>m;
        for(int i=0;i<v.size();i++){
            if(m[v[i].second]<k && t){
                t--;
                ans+=v[i].first;
                m[v[i].second]++;
            }
        }
        return ans;
        
    }
};