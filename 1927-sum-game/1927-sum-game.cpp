class Solution {
public:
    bool sumGame(string v) {
        int lc=0;
        int rc=0;
        int ls=0;
        int rs=0;
        int n=v.size();
        for(int i=0;i<v.size();i++){
            if(i<(n/2)){
                lc+=(v[i]=='?');
                if(v[i]!='?')
                ls+=(v[i]-'0');
            }
            else{
                rc+=(v[i]=='?');
                if(v[i]!='?')
                rs+=(v[i]-'0');
            }
        }
        if((rc+lc)%2){
            cout<<"Dfs";
            return true;
        }
        else{
            int x = min(rc,lc);
            rc-=x;
            lc-=x;
            // cout<<ls<<" "<<lc<<" "<<rs<<" "<<rc<<endl; 
            return ((ls + (lc/2)*9)!=(rs+(rc/2)*9));
        }
    }
};