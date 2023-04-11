class Solution {
public:
    string removeStars(string s) {
        int count=0;
        vector<int>visited(s.size());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*'){
                count++;
                visited[i]=1;
            }
            else if(count){
                visited[i]=1;
                count--;
            }
            
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(visited[i]==0){
                ans+=s[i];
            }
        }
        return ans;
    }
};