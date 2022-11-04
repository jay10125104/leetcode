class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>stackvisited(26);
        map<char,int>m;
        stack<char>st;
        for(auto &i:s){
            m[i]++;
        }
        for(int i=0;i<s.size();i++){
            m[s[i]]--;
            if(stackvisited[s[i]-'a']){
                continue;
            }
            while(st.size() && st.top()>s[i] && m[st.top()]){
                stackvisited[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            stackvisited[s[i]-'a']=1;
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};