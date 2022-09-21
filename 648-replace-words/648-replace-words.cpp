struct node{
    node*links[26];
    
    string flag="";
};
class Trie {
public:
    node*root;
    Trie() {
        root = new node();
    }
    
    void insert(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] =  new node();
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->flag = s;
    }
    
    string search(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                // sol.push_back(s);
                return s;
            }
            else{
                temp = temp->links[s[i]-'a'];
            }
            if(temp->flag!=""){
                return temp->flag;
            }
        }
        return s;
    }
    
    bool startsWith(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                return false;
            }
            else{
                temp = temp->links[s[i]-'a'];
            }
        }
        return true;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        vector<string>v;
        string mid="";
        Trie *t = new Trie();
        for(auto i:d){
            t->insert(i);
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(mid);
                mid="";
            }
            else{
                mid+=s[i];
            }
        }
        // t->insert(mid);
        v.push_back(mid);
        vector<string>sol;
        for(int i=0;i<v.size();i++){
            sol.push_back(t->search(v[i]));
        }
        string ans="";
        for(int i=0;i<sol.size();i++){
            ans+=sol[i];
            if(i!=sol.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};