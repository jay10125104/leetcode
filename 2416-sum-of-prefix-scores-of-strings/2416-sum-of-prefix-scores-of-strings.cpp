bool cmp(string &a,string &b){
    return a.size()<b.size();
}
struct node{
    node*links[26];
    bool flag=false;
    int count=0;
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
            temp->count++;
        }
        temp->flag = true;
    }
    
    int search(string s) {
        node*temp = root;
        int sum=0;
        for(int i=0;i<s.size();i++){
                temp = temp->links[s[i]-'a'];
            sum+=temp->count;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& s) {
        vector<string>ti = s;
        sort(s.begin(),s.end(),cmp);
        Trie *t = new Trie();
        for(auto i:s){
            t->insert(i);
        }
        vector<int>ans;
        for(auto i:ti){
            ans.push_back(t->search(i));
        }
        return ans;
        
        
    }
};