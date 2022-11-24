class Solution {
public:
    int findTheLongestSubstring(string s) {
        int bit=0;
        int ans=0;
        map<int,int>m;
        m[0]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                int x = pow(2,s[i]-'a');
                bit = bit^x;
            }
            if(m.find(bit)!=m.end()){
                ans = max(ans,i-m[bit]);
            }
            else{
                m[bit] = i; 
            }
        }
        return ans;
        
    }
};