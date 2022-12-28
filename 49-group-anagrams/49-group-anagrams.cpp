class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>v;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            v.push_back({s,i});
        }
        map<string,vector<string>>m;
        for(auto &i:v){
            m[i.first].push_back(strs[i.second]);
        }
        vector<vector<string>>sol;
        for(auto &i:m){
            sol.push_back(i.second);
        }
        return sol;
        
    }
};