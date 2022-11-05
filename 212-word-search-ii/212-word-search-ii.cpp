struct node{
  node*links[26];
    string str="";
    int flag=0;
};
class Trie{
    public:
    node*root;
  Trie(){
      root = new node();
  }
    void insert(string s){
        node*temp = root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a'] = new node();
            }
           temp=temp->links[s[i]-'a'];
        }
        temp->flag = 1;
        temp->str = s;
    }
};
void dfs(vector<vector<char>>&v,int i,int j,node*temp,vector<vector<int>>&visited,vector<string>&ans){
    if(i<0 || j<0 || i==v.size() || j == v[0].size() || visited[i][j]==1){
        return;
    }
    if(temp->links[v[i][j]-'a']==NULL){
        return;
    }
    else{
        temp = temp->links[v[i][j]-'a'];
        if(temp->flag){
            ans.push_back(temp->str);
            temp->flag=0;
        }
    }
    visited[i][j]=1;
    dfs(v,i,j-1,temp,visited,ans);
    dfs(v,i,j+1,temp,visited,ans);
    dfs(v,i-1,j,temp,visited,ans);
    dfs(v,i+1,j,temp,visited,ans);
    visited[i][j]=0;
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& v, vector<string>& words) {
        vector<string>ans;
        Trie *t = new Trie(); 
        for(auto &i:words){
            t->insert(i);
        }
        int m=v.size();
        int n = v[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                node*temp = t->root;
                dfs(v,i,j,temp,visited,ans);
            }
        }
        return ans;
    }
};