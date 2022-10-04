class Solution {
public:
    bool ans(vector<vector<char>>& v,string s,int idx,int i,int j,vector<vector<int>>&visited){
        // cout<<i<<" "<<j<<endl;
       
        if(idx>=s.size()){
            return true;
        }
        if(i<0 || j<0 || i==v.size() || j==v[0].size() || visited[i][j] || s[idx]!=v[i][j]){
            return false;
        }
        visited[i][j]=1;
        bool x = ans(v,s,idx+1,i,j+1,visited);
        bool y =ans(v,s,idx+1,i,j-1,visited);
        bool z = ans(v,s,idx+1,i+1,j,visited);
        bool a = ans(v,s,idx+1,i-1,j,visited);
        visited[i][j]=0;
        return x|y|z|a;
    }
    bool exist(vector<vector<char>>& v, string s) {
        bool x = false;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==s[0]){
                    vector<vector<int>>visited(v.size(),vector<int>(v[0].size()));
                    x = x | ans(v,s,0,i,j,visited);
                    if(x){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};