struct node{
    node*links[26];
    bool flag=false;
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
        temp->flag = true;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& v) {
       Trie *t=new Trie();
        for(auto i:v){
            t->insert(i);
        }
        node*temp = t->root;
        vector<string >sol;
        queue<pair<node*,string>>q;
        q.push({temp,""});
        for(int i=0;i<s.size();i++){
            // cout<<i<<endl;
            int x = q.size();
            while(x--){
                auto it = q.front();
                // cout<<it.second<<" ";
                q.pop();
                if(it.first->flag && temp->links[s[i]-'a']!=NULL){
                    q.push({temp->links[s[i]-'a'],it.second+' '+s[i]});
                }
                if(it.first->links[s[i]-'a']!=NULL){
                    q.push({it.first->links[s[i]-'a'],it.second+s[i]});
                }
            }
            // cout<<endl;
        }
        // cout<<q.size()<<" ";
        while(q.size()){
            if(q.front().first->flag)
            sol.push_back(q.front().second);
            q.pop();
        }
        return sol;
    }
};