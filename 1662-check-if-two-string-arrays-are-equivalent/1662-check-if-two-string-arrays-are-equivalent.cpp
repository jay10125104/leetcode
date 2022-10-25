class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& s, vector<string>& t) {
        string a="";
        string b="";
        for(auto &i:s){
            a+=i;
        }
        for(auto i:t){
            b+=i;
        }
        return a==b;
    }
};