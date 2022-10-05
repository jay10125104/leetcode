struct node{
    node*links[10];
    bool flag=false;
    string str="";
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
            if(temp->links[s[i]-'0']==NULL){
                temp->links[s[i]-'0'] =  new node();
            }
            temp = temp->links[s[i]-'0'];
        }
        temp->flag = true;
        temp->str = s;
    }
    
    void search(node*temp,vector<int>&sol) {
        if(temp->flag){
            sol.push_back(stoi(temp->str));
        }
       for(auto i:temp->links)
           if(i!=NULL){
               search(i,sol);
           }
    }
    };
class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        Trie*t = new Trie();
        for(int i=1;i<=n;i++){
            string mid = to_string(i);
            t->insert(mid);
        }
        vector<int>sol;
        t->search(t->root,sol);
        return sol;
    }
};