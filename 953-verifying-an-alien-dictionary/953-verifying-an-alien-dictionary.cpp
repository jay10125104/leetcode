map<char,int>m;
bool cmp(string &s,string &t){
    for(int i=0;i<min(s.size(),t.size());i++){
        if(s[i]!=t[i]){
            return m[s[i]]<m[t[i]];
        }
    }
    return s.size()<t.size();
}
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string>v = words;
        int count=1;
        for(auto &i:order){
            m[i] = count;
            count++;
        }
        sort(v.begin(),v.end(),cmp);
        return v==words;
    }
};