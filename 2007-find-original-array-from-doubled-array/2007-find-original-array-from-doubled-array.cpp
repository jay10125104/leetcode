class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        map<int,int>m;
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto i:v){
            if(m[i]==0){
                m[2*i]++;
                ans.push_back(i);
            }
            else{
                m[i]--;
            }
        }
        for(auto i:m){
            if(i.second>=1){
                return {};
            }
        }
        return ans;
    }
};