class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans=0;
        int j=0;
        vector<int>v(1000,0);
        for(int i=0;i<s.size();i++){
            int x =s[i];
            v[x]++;
            while(v[x]>=2){
                int t=s[j];
                v[t]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};