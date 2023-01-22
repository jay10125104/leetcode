class Solution {
public:
    int pal[17][17];
    vector<vector<string>>sol;
    void ans(vector<vector<string>>&s,int idx,vector<string>&mid){
        if(idx==s.size()){
            sol.push_back(mid);
            return;
        }
        else{
            for(int i=idx;i<s.size();i++){
                if(pal[idx][i]){
                    mid.push_back(s[idx][i]);
                    ans(s,i+1,mid);
                    mid.pop_back();
                    
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>st(n,vector<string>(n,""));
        memset(pal,0,sizeof(pal));
        for(int i=n-1;i>=0;i--){
            string mid="";
            for(int j=i;j<n;j++){
                mid+=s[j];
                if(i==j){
                    pal[i][j]=1;
                }
                else if(((i+1)==j) && (s[i]==s[j])){
                    pal[i][j]=1;
                }
                else if(s[i]==s[j] && pal[i+1][j-1]){
                    pal[i][j]=1;
                }
                st[i][j] = mid;
                
            }
        }
        vector<string>mid;
        ans(st,0,mid);
        return sol;
        
        
    }
};