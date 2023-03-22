class Solution {
public:
    int minFlips(string s) {
        string ans="";
        int flag=0;
        for(auto &i:s){
            if(i=='1'){
                flag=1;
            }
            if(flag)
            ans+=i;
        }
        int sol=0;
        if(ans.size()){
            sol=1;
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]){
                sol++;
            }
        }
        return sol;
        
    }
};