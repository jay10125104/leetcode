bool cmp(string &a,string &b){
    return(a.size()<b.size());
}
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
    
    bool insert(string s) {
       node*temp = root;
        queue<node*>q;
        int idx=0;
        q.push(temp);
        while(q.size()&&idx<s.size()){
            int x = q.size();
            // cout<<s<<" "<<x<<" ";
            while(x--){
                auto it = q.front();
                q.pop();
                if(it->links[s[idx]-'a']!=NULL){
                    q.push(it->links[s[idx]-'a']);
                }
                if(it->flag==1){
                   auto it = root->links[s[idx]-'a'];
                    if(it!=NULL){
                        q.push(it);
                    }
                }
            }
            idx++;
        }
        while(q.size()){
            auto it = q.front();
            q.pop();
            if(it->flag){
                return true;
            }
        }
        return false;
    }
        
    void rinsert(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a']=new node();
                
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->flag = true;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& v) {
        sort(v.begin(),v.end(),cmp);
        vector<string>ans;
        Trie *t = new Trie();
        for(auto i:v){
            // cout<<i<<" ";
            if(t->insert(i)){
                ans.push_back(i);
            }
            t->rinsert(i);
        }
        return ans;
    }
};