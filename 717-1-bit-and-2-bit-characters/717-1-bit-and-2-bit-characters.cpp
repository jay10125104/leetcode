class Solution {
public:
    bool isOneBitCharacter(vector<int>& s) {
       int i=0;
        int j=1;
        while(j<s.size()){
            if((s[i]==1 && s[j]==0 )|| (s[i]==1 && s[j]==1)){
                i+=2;
                j+=2;
            }
            else{
                i++;
                j++;
            }
            
        }
        if(j==s.size()){
            return true;
        }
        return false;
    }
};