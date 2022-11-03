class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0){
                st.push('(');
            }
            else if(s[i]=='('){
                ans+='(';
                st.push('(');
            }
            else if(s[i]==')' && st.size()!=1){
                ans+=')';
                st.pop();
            }
            else{
                st.pop();
            }
        }
        return ans;
    }
};