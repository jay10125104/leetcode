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
    
    void insert(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] =  new node();
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->flag++;
    }
    
    int search(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                return 0;
            }
            temp = temp->links[s[i]-'a'];
        }
        return temp->flag;
    }
    bool search1(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            // if()
            if(temp->links[s[i]-'a']==NULL){
                return false;
            }
            temp = temp->links[s[i]-'a'];
        }
        return temp->flag;
    }
    
};
class Encrypter {
public:
    map<char,string>m;
    map<string,vector<char>>m1;
    Trie *t = new Trie();
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& d) {
        int count=0;
        for(auto i:keys){
            m[i]=values[count];
            count++;
        }
        count=0;
        for(auto i:values){
            m1[i].push_back(keys[count]);
            count++;
        }
        for(auto i:d){
            string mid=i;
            int idx=0;
            string to_add="";
            int flag=0;
            while(idx<mid.size()){
                if(m.find(mid[idx])==m.end()){
                    flag=1;
                    break;
                }
                to_add = to_add + m[mid[idx]];
                idx++;
            }
            if(flag==0)
            t->insert(to_add);   
        }
    }
    
    
    string encrypt(string s) {
        string mid="";
        for(auto i:s){
            mid+=m[i];
        }
        return mid;
    }
    
    int decrypt(string s) {
        return t->search(s);
        }
        
        // return ans;
    
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */