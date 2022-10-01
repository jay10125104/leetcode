class Solution {
public:
    string convert(string s, int x) {
        vector<vector<char>>ans(1000,vector<char>(1000,'*'));
        int flag=1;
        int r=-1;
        int c=0;
        string sol="";
        x--;
        if(x==0){
            return s;
        }
        for(int i=0;i<s.size();i++){
            if( (c%x==0)){
                flag=1;
            }
            if(r==x){
                flag=0;
                // r--;
            }
            if(flag==1){
                r++;
            }
            else{
                r--;
                c++;
            }
            ans[r][c] = s[i];
            // cout<<r<<" "<<c<<" "<<flag<<endl;
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                // cout<<ans[i][j]<<" ";
                if(ans[i][j]!='*'){
                    sol+=ans[i][j];
                }
            }
            // cout<<endl;
        }
        return sol;
    }
};