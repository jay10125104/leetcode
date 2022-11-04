class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        map<int,int>m;
        for(auto &i:target){
            m[i]++;
        }
        vector<string>ans;
        for(int i=1;i<=target[target.size()-1];i++){
            if(m[i]){
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};