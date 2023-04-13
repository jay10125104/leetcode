class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            char x = '0'+i;
            s+=x;
        }
        k--;
        while(k--){
            // cout<<s<<endl;
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};