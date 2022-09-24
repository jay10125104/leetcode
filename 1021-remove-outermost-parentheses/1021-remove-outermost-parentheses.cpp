class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        int close=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            open+=((s[i]=='(')?(1):(0));
            close+=((s[i]==')')?(1):(0));
            if(open==1 || close==open){
                if(close==open){
                    open=0;
                    close=0;
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};