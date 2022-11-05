struct node{
    node*links[26];
    bool flag=false;
    string real="";
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
        temp->real = s;
        temp->flag = true;
    }
};
class Solution {
public:
    void ans(vector<vector<char>>&v,node*temp,int i,int j,vector<vector<int>>&visited,set<string>&sol){
         if(i<0 || j<0 || i>=v.size()||j>=v[0].size()){
            return;
        }
        if(temp->links[v[i][j]-'a']==NULL || visited[i][j]==1){
            return;
        }
        else{
            temp=temp->links[v[i][j]-'a'];
            if(temp->flag){
            sol.insert(temp->real);
            }
        }
        
        visited[i][j]=1;
        ans(v,temp,i,j-1,visited,sol);
        ans(v,temp,i+1,j,visited,sol);
        ans(v,temp,i-1,j,visited,sol);
        ans(v,temp,i,j+1,visited,sol);
        visited[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& v, vector<string>& s) {
        Trie *t = new Trie();
        for(auto i:s){
            t->insert(i);
        }
        int m=v.size();
        int n=v[0].size();
        vector<string>sol;
        set<string>sol2;
                vector<vector<int>>visited(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                node*temp = t->root;
                ans(v,temp,i,j,visited,sol2);
            }
        }
        for(auto &i:sol2){
            sol.push_back(i);
        }
        return sol;
    }
};