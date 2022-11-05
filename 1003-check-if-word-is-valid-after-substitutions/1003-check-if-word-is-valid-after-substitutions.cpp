class Solution {
public:
    stack<char>st;
    bool isValid(string s) {
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            while(st.size()  && st.top()=='c'){
                // cout<<2;
                char third = st.top();
                st.pop();
                char second = '*';
                char first = '*';
                if(st.size()){
                    second=st.top();
                    st.pop();
                }
                if(st.size()){
                    first=st.top();
                    st.pop();
                }
                if(first=='a' && second=='b' && third=='c'){
                    
                }
                else{
                    if(first!='*')
                    st.push(first);
                    if(second!='*')
                    st.push(second);
                    if(third!='*')
                    st.push(third);
                    break;
                }
            }
        }
        return st.size()==0;
    }
};