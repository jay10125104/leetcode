class Solution {
public:
    bool check(string& s,string& s1,int i){
        if(i>=s.size()) return true;
        if(i+s1.size()>s.size()) return false;
        if(s.substr(i,s1.size())==s1) return check(s,s1,i+s1.size());
        else return false;
    }
    bool repeatedSubstringPattern(string s) {
       for(int i=0;i<s.size();i++){
           int size = i+1;
           if(s.size()%size==0 && s.size()!=size){
               string mid = s.substr(0,size);
               int k = s.size()/size;
               string t = "";
               while(k--){
                   t+=mid;
               }
               if(t==s){
                   // cout<<mid<<" ";
                   return true;
               }
           }
       }
        return false;
    }
};