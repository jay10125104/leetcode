struct node{
    node*links[26];
    int flag=0;
};
class Trie {
public:
    node*root;
    Trie() {
        root = new node();
    }
    
    void insert1(string s,int x,int y) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] =  new node();
            }
            temp = temp->links[s[i]-'a'];
            temp->flag+=(x-y);
        }
    }
    
    bool search(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                return 0;
            }
            else{
                temp = temp->links[s[i]-'a'];
            }
        }
        return temp->flag;
    }
    
    int startsWith(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                return 0;
            }
            else{
                temp = temp->links[s[i]-'a'];
            }
        }
        return temp->flag;
    }
};
class MapSum {
public:
    Trie*r;
    map<string,int>m;
    MapSum() {
        r= new Trie();
    }
    
    void insert(string key, int val) {
        r->insert1(key,val,m[key]);
        m[key]=val;
    }
    
    int sum(string prefix) {
        return r->startsWith(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */