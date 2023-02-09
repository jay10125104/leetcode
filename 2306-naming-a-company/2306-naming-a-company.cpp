class Solution {
public:
    long long distinctNames(vector<string>& s) {
       vector<unordered_set<string>>v(26);
        for(auto &i:s){
            v[i[0]-'a'].insert(i.substr(1));
        }
        long long int ans=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                unordered_set<string>mid;
                for(auto &k:v[i]){
                    mid.insert(k);
                }
                for(auto &k:v[j]){
                    mid.insert(k);
                }
                ans+=2*(mid.size()-v[i].size())*(mid.size()-v[j].size());
            }
        }
        return ans;
    }
};