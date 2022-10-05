struct node{
    node*links[26];
    int flag=false;
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
        queue<pair<node*,char>>q;
        for(int i=0;i<=25;i++){
            if(temp->links[i]!=NULL)
            q.push({temp->links[i],'a'+i});
        }
        int idx=0;
        int count=0;
        while(idx<s.size()&&q.size()){
            int x = q.size();  
            while(x--){
                auto it = q.front();
                q.pop();
                if(it.second==s[idx]){
                    if(it.first->flag){
                    count+=it.first->flag;
                    it.first->flag=0;
                    }
                    // cout<<it.second<<" ";
                   
                    for(int i=0;i<=25;i++){
                        if(it.first->links[i]!=NULL){
                            q.push({it.first->links[i],'a'+i});
                        }
                    }
                }
                else{
                    q.push(it);
                }
            }
            idx++;
        }
        return count;
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
    int numMatchingSubseq(string s, vector<string>& v) {
        Trie *t  = new Trie();
        for(auto i:v){
            t->insert(i);
        }
        // vector<string>ans;
        // t->search(s,ans);
        return t->search(s);
    }
};