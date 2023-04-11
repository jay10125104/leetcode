class Solution {
public:
    unordered_map<string,int>m;
    bool check(string &s,int sz){
        unordered_map<string,int>m1;
        for(int i=0;i+sz<=s.size();i+=sz){
            string mid = s.substr(i,sz);
            m1[mid]++;
        }
        return m1==m;
    }
    vector<int> findSubstring(string s, vector<string>& t) {
        vector<int>ans;
        int n=t.size();
        int req = t[0].size()*n;
        for(auto &i:t){
            m[i]++;
        }
        int sz = t[0].size();
        for(int i=0;i+req<=s.size();i++){
            string mid = s.substr(i,req);
            // cout<<mid<<endl;
            if(check(mid,(int)t[0].size())){
                ans.push_back(i);
            }
        }
        return ans;
    }
};