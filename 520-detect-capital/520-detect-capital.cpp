class Solution {
public:
    bool detectCapitalUse(string word) {
        string ans = word;
        transform(ans.begin(),ans.end(),ans.begin(),::toupper);
        if(word==ans){
            return true;
        }
        else{
            
        
        for(int i=1;i<word.length();i++){
            if(word[i]>='A'&&word[i]<='Z'){
                return false;
                break;
            }
        }
        }
        return true;
    }
};