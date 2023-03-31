class Solution {
public:
    int check(vector<vector<int>>&t){
        int ans=0;
        for(auto &i:t){
            for(auto &j:i){
                ans+=j;
            }
        }
        return ((ans==0)?(0):(1e6));
    }
    void sol(vector<vector<int>>&t,int i,int j){
        if(i-1>=0){
            t[i-1][j]^=1;
        }
        if(i+1<t.size()){
            t[i+1][j]^=1;
        }
        if((j-1)>=0){
            t[i][j-1]^=1;
        }
        if(j+1<t[0].size()){
            t[i][j+1]^=1;
        }
        t[i][j]^=1;
        // return sol;
    }
    int ans(vector<vector<int>>&v,int i,int j,int m,int n){
        if(i==m){
            j++;
            i=0;
        }
        if(j==n){
            return check(v);
        }
        int one = ans(v,i+1,j,m,n);
        vector<vector<int>>t =v;
        sol(t,i,j);
        int two = ans(t,i+1,j,m,n)+1;
        return min(one,two);
    }
    int minFlips(vector<vector<int>>&v) {
        int m=v.size();
        int n=v[0].size();
        int sol = ans(v,0,0,m,n);
        return sol==1e6?(-1):sol;
    }
};