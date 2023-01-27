class Solution {
public:
    set<string>sol;
    void ans(string &s,vector<int>&visited,string &mid){
        for(int i=0;i<s.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                mid+=s[i];
                sol.insert(mid);
                ans(s,visited,mid);
                mid.pop_back();
                visited[i]=0;
            }
        }
    }
    int numTilePossibilities(string s) {
        string t="";
        vector<int>visited(s.size(),0);
        ans(s,visited,t);
        return sol.size();
        
    }
};