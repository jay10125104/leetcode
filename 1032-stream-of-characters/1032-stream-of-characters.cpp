struct node{
    node*links[26];
    int x = 0;
};
class Trie{
public:
    node*root;
    Trie(){
        root = new node();
    }
    void insert(string &s){
        node*temp = root;
        for(int i=s.size()-1;i>=0;i--){
            // cout<<s<<" "<<s[i]<<"\n";
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] = new node();
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->x = 1;
    }
    bool query1(string &s){
        node*temp = root;
        for(int i=s.size()-1;i>=0;i--){
            if(temp->links[s[i]-'a']==NULL){
                return false;
            }
            else{
                temp = temp->links[s[i]-'a'];
                if((temp->x)==1){
                    // s[]
                    return true;
                }
            }
        }
        return false;
    }
};
class StreamChecker {
public:
    Trie *t = new Trie();
    string s="";
    StreamChecker(vector<string>& v) {
        for(auto &i:v){
            // reverse(i.begin(),i.end());
            t->insert(i);
        }
    }
    
    bool query(char letter) {
        s = s + letter;
        // string mid = s;
        // reverse(mid.begin(),mid.end());
        if(s.size()>200){
            s.erase(s.begin());
        }
        return t->query1(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */