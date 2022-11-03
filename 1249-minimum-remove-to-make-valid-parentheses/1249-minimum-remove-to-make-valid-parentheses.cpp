class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int>st;
        vector<int>valid(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')' && st.size()){
                valid[i]=1;
                valid[st.top()]=1;
                st.pop();
            }
            else if(s[i]!=')'){
                valid[i]=1;
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(valid[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};