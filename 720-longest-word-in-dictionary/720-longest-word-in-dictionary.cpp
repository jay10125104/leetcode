bool cmp(string &a,string &b){
    return a.size()<b.size();
}
struct node{
    int val = 0;
    node*links[26];
};
class Trie{
    
    public:
    node*root;
    Trie() {
        root = new node();
    }
    bool insert(string s){
        int count=0;
        node*temp = root;
        for(int i=0;i<s.size();i++){
            // cout<<i<<" "<<s<<endl;
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] = new node();
            }
        
             temp = temp->links[s[i]-'a'];
            count+=temp->val;
            
        }
        temp->val=1;
        count+=temp->val;
        return (count==s.size());
    }
};
class Solution {
public:
    string longestWord(vector<string>& v) {
        sort(v.begin(),v.end(),cmp);
        Trie*t = new Trie();
        string ans="";
        for(auto i:v){
            if(t->insert(i)){
                // cout<<i<<" ";
                if(i.size()>=ans.size()){
                    if(i.size()==ans.size()){
                        if(i<ans){
                            ans=i;
                        }
                    }
                    else{
                        ans=i;
                    }
                }
            }
        }
        return ans;
        }
};