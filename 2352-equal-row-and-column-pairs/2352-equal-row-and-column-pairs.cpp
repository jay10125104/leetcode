class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        map<vector<int>,int>s;
        int n=v.size();
        for(int i=0;i<n;i++){
            vector<int>mid;
            for(int j=0;j<n;j++){
                mid.push_back(v[j][i]);
            }
            s[mid]++;
        }
        int ans=0;
        for(auto &i:v){
                ans+=s[i];
        }
        return ans;
    }
};