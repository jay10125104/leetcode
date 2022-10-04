struct node{
    node*links[27];
    bool flag=false;
    int idx=-1;
};
class Trie {
public:
    node*root;
    Trie() {
        root = new node();
    }
    
    void insert(string s,int count) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(temp->links[26]==NULL){
                    temp->links[26] =  new node();
                }
                temp = temp->links[26];
                temp->idx=count;
                continue;
            }
            
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] =  new node();
            }
            temp = temp->links[s[i]-'a'];
            temp->idx=count;
        }
        
        temp->flag = true;
    }
    
    int search(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(temp->links[26]==NULL){
                    return -1;
                }
                else{
                    temp = temp->links[26];
                }
                continue;
            }
            if(temp->links[s[i]-'a']==NULL){
                return -1;
            }
            else{
                temp = temp->links[s[i]-'a'];
            }
        }
        return temp->idx;
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
class WordFilter {
public:
    Trie*t = new Trie();
    WordFilter(vector<string>& v) {
        int count=0;
        for(auto i:v){
            string ti="";
            for(int j=i.size()-1;j>=0;j--){
                ti = i[j] + ti;
                string to_add = ti+"*"+i;
                // cout<<to_add<<" ";
                t->insert(to_add,count);
            }
            count++;
            
        }
    }
    
    int f(string pref, string suff) {
        string req = suff+"*"+pref;
        return t->search(req);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */