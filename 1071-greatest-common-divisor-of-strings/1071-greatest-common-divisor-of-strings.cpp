class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if(s.size()<t.size()){
            return gcdOfStrings(t,s);
        }
        string mid="";
        string ans="";
        for(int i=0;i<t.size();i++){
            mid+=t[i];
            // cout<<mid<<" ";
            if(s.size()%mid.size()==0 && t.size()%mid.size()==0){
                // cout<<mid<<" ";
                int x = s.size()/mid.size();
                int x2 = t.size()/mid.size();
                string st="";
                while(x--){
                    st+=mid;
                }
                string st2="";
                while(x2--){
                    st2+=mid;
                }
                if(st==s && st2==t){
                    ans = mid;
                }
            }
        }
        return ans;
    }
};