struct node{
    map<string,node*>links;
    int flag=0;
};
class Trie {
public:
    node*root;
    // int count=0;
    // map<string,int>m;
    Trie() {
        root = new node();
    }
    
    bool insert(string s) {
        node*temp = root;
        for(int i=1;i<s.size();i++){
            string mid="";
            // int x;
            for(int j=i;j<s.size();j++){
                if(s[j]=='/'){
                    i = j;
                    break;
                }
                else{
                    mid+=s[j];
                }
                if(j==s.size()-1){
                    i = j;
                }
            }
            // cout<<s<<" "<<mid<<" ";
            if(temp->links[mid]==NULL){
                temp->links[mid] =  new node();
            }
            temp = temp->links[mid];
            if(temp->flag==1){
                return true;
            }
        }
        temp->flag = 1;
        return false;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>&v) {
        sort(v.begin(),v.end());
        vector<string>ans;
        Trie *t = new Trie();
        for(auto i:v){
            if(t->insert(i)==false){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};