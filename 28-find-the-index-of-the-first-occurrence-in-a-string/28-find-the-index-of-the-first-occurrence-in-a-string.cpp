class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        if(needle ==""){
            ans= 0;
        }
        
        return ans;
    }
};