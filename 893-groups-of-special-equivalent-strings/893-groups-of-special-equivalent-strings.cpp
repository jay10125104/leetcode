class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n=words.size();
    
        vector<map<char,int>>v1(n);
        vector<map<char,int>>v2(n);
        for(int j=0;j<words.size();j++){
            string s = words[j];
            for(int i=0;i<s.size();i++){
                if(i%2){
                    v1[j][s[i]]++;
                }
                else{
                    v2[j][s[i]]++;                    
                }
            }
        }
        set<pair<map<char,int>,map<char,int>>>s;
        for(int i=0;i<n;i++){
            s.insert({v1[i],v2[i]});
        }
        return s.size();
    }
};