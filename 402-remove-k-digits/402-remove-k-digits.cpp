class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(st.size() && st.top()>s[i] && k){
                k--;
                st.pop();
            }
            
            st.push(s[i]);
        }
        while(k--){
            st.pop();
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string sol="";
        int flag=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                flag=1;
            }
            if(flag==1){
                sol+=ans[i];
            }
        }
        if(sol.size())
        return sol;
        else{
            return "0";
        }
        
    }
};