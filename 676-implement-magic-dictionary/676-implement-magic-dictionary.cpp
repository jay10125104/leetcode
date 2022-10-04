struct node{
    node*links[26];
    bool flag=false;
};
class Trie{
    public:
    node*root;
    Trie(){
        root = new node();
    }
    void insert(string s){
        node*temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] = new node();
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->flag=true;
    }
    bool query(string s){
        node*temp = root;
        int count=0;
        int i=0;
        queue<pair<node*,int>>q;
        q.push({temp,0});
        while(i<s.size()&&q.size()){
            int x = q.size();
            
            while(x--){
                auto it = q.front();
                // cout<<it.second<<" "<<s[i]<<" "<<s<<endl;
                q.pop();
                if(it.second!=2){
                    for(char x='a';x<='z';x++){
                        if(it.first->links[x-'a']!=NULL && x!=s[i]){
                            q.push({it.first->links[x-'a'],it.second+1});
                        }
                        else if(it.first->links[x-'a']!=NULL){
                            q.push({it.first->links[x-'a'],it.second});
                        }
                    }
                }
                else if(it.first->links[s[i]-'a']!=NULL){
                    q.push({it.first->links[s[i]-'a'],it.second});
                }
            }
            i++;
        }
        while(q.size()){
            auto it = q.front();
            q.pop();
            if(it.first->flag && it.second==1){
                return true;
            }
        }
        return false;
    }
};
class MagicDictionary {
public:
    Trie *t = new Trie();
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> v) {
        for(auto i:v){
            t->insert(i);
        }
    }
    
    bool search(string x) {
        return t->query(x);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */