struct node{
    node*links[26];
    bool end = false;
}; //initializing struct array;
class WordDictionary {
public:
    node*root;
    WordDictionary() {
        root=new node(); //its just initialization;
    }
    
    void addWord(string s) {
        int n=s.size();
        node*temp = root;
        for(int i=0;i<n;i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] = new node(); //adding new node;
            }
            temp = temp->links[s[i]-'a']; //if node is present just move on
        }
        temp->end = true; //make it as end;
    }
    bool ans(string &s,int idx,node*temp){
        if(idx==s.size()){
            return temp->end; //if string end is reached then we just need to return whether its a end of a string or not;
        }
        else if(s[idx]=='.'){ //iterate over its next nodes and finally return throught it;
            for(auto it:temp->links){
                if(it!=NULL && ans(s,idx+1,it)){
                    return true;
                }
            }
            return false; //if not got the value then return false;
        }
        else{
            if(temp->links[s[idx]-'a']==NULL){
                return false; //if not found return false;
            }
            else{
                temp = temp->links[s[idx]-'a']; //return the temp's that node;
                return ans(s,idx+1,temp); //return the val of next node;
            }
        }
    }
    bool search(string s) {
        node*temp = root;
        return ans(s,0,temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */