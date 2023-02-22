class Solution {
public:
    int maximumSwap(int num) {
        int ans=0;
        string s = to_string(num);
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                string x = s;
                swap(x[i],x[j]);
                ans = max(ans,stoi(x));
            }
        }
        return ans;
    }
};