class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>v(26,0);
        vector<int>t(26,0);
        for(auto &i:s){
            v[i-'a']++;
        }
        int prev=0;
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']--;
            t[s[i]-'a']++;
            int flag=0;
            for(int j=0;j<26;j++){
                if(t[j] && v[j]){
                    flag=1;
                }
            }
            if(flag==0){
                ans.push_back(i-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};