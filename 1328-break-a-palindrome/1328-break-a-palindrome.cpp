class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1){
            return "";
        }
        else{
            int ans=0;
            for(auto i:s){
                ans+=((i-'a')==0);
            }
            cout<<ans<<" ";
            if(ans==(s.size()-1) && (s.size()%2 && s[s.size()/2]!='a')){
                s[s.size()-1]='b';
                return s;
            }
            int flag=1;
            for(int i=0;i<s.size();i++){
                if(s[i]!='a'){
                    s[i]='a';
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                s[s.size()-1]='b';
            }
            return s;
        }
    }
};