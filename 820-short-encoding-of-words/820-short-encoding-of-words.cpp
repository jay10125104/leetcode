bool cmp(string s,string t){
    return s.size()<t.size();
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
    
    void insert(string s) {
        node*temp = root;
        for(int i=s.size()-1;i>=0;i--){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] =  new node();
            }
            if(temp->flag==true){
                temp->flag=false;
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->flag = true;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& v) {
        Trie *t = new Trie();
        sort(v.begin(),v.end(),cmp);
        for(auto i:v){
            t->insert(i);
        }
        node*temp = t->root;
        queue<node*>q;
        q.push(temp);
        int count=0;
        int ans=0;
        while(q.size()){
            int x = q.size();
            while(x--){
                node*mid = q.front();
                
                q.pop();
                if(mid->flag){
                    ans+=(count+1);
                }
                for(auto i:mid->links){
                    if(i!=NULL){
                        q.push(i);
                    }
                }
            }
            count++;
        }
        return ans;
    }
};