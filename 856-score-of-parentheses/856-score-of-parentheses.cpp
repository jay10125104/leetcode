class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int count=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(-1);
            }
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int sol=-1;
                    while(st.top()!=-1){
                        if(sol==-1){
                            sol = st.top();
                            st.pop();
                        }
                        else{
                            sol = sol+st.top();
                            st.pop();
                        }
                    }
                    st.pop();
                    st.push(2*sol);
                }
            }
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};