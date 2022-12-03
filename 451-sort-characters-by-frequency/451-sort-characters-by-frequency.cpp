class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        vector<pair<int,char>>v;
        for(auto &i:s){
            m[i]++;
        }
        for(auto &i:m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string ans="";
        for(auto &i:v){
            int t = i.first;
            while(t--){
                ans+=i.second;
            }
        }
        return ans;
    }
};