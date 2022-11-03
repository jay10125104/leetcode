class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                string mid = "";
                while(st.top()!='('){
                    mid+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto &it:mid){
                    
                    st.push(it);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(st.size()){
            ans = (st.top())+ans;
            st.pop();
        }
        return ans;
    }
};