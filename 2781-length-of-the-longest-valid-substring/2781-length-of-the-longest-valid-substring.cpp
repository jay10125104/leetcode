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
    
    bool search(string s) {
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                return false;
            }
            else{
                temp = temp->links[s[i]-'a'];
            }
        }
        return temp->flag;
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
    
    int longestValidSubstring(string s, vector<string>& ti) {
        int n=s.size();
        Trie *t = new Trie();
        for(auto &i:ti){
            t->insert(i);
        }
        
        int mn[n];
        memset(mn,-1,sizeof(mn));
        for(int i=0;i<n;i++){
            int count=1;
            for(int j=i;j<n && (count<=10);j++){
                string mid=s.substr(i,count);
                if(t->search(mid)){
                        mn[j]=max(mn[j],i);
                }
                count++;
            }
        }
        int ans=0;
        int prev=-1;
        for(int i=0;i<n;i++){
            
                prev=max(prev,mn[i]);
        
            ans=max(ans,i-prev);
            // cout<<i<<" "<<prev<<" "<<ans<<"\n";
        }
        // cout<<endl;
        return ans;
    }
};