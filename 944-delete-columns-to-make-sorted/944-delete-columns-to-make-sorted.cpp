class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        string s = strs[0];
        int count=0;
        for(int j=0;j<s.size();j++){
        char prev = s[j];
        for(int i=1;i<strs.size();i++){
            if(strs[i][j]>=prev){
                prev = strs[i][j];
            }
            else{
                count++;
                break;
            }
        }
        }
        return count;
    }
};