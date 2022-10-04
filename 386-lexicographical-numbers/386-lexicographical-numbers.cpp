bool cmp(string &a,string &b){
    return a<b;
}
class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++){
            string mid = to_string(i);
            ans.push_back(mid);
        }
        vector<int>sol;
        sort(ans.begin(),ans.end(),cmp);
        for(auto i:ans){
            sol.push_back(stoi(i));
        }
        return sol;
    }
};