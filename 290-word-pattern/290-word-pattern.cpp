class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string>m;
        map<string,char>m1;
        int j=0;
        
        int i=0;
        for(i=0;i<p.size();i++){
            string ans="";  
            while(j<s.size() && s[j]!=' '){
                ans+=s[j];
                j++;
            }
            if(ans==""){
                return false;
            }
            if(j!=s.size())
            j++;
            if(m.find(p[i])!=m.end() && m[p[i]]==ans){
                
            }
            else if(m.find(p[i])==m.end()){
                m[p[i]] = ans;
            }
            else{
                cout<<p[i]<<" "<<ans<<endl;
                return false;
            }
            if(m1.find(ans)!=m1.end() && m1[ans]!=p[i]){
                cout<<m1[ans]<<" ";
                return false;
            }
            else{
                m1[ans] = p[i];
            }
        }
        // cout<<i<<" "<<j<<endl
        return (i==p.size() && j==s.size());
    }
};