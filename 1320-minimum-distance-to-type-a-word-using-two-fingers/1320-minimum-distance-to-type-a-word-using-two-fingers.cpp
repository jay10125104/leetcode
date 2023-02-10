class Solution {
public:
    int dp[10][10][10][10][301];
    map<char,pair<int,int>>m;
    int sol(string &s,int i,int j,int a,int b,int idx){
        if(idx==s.size()){
            return 0;
        }
        else if(dp[i][j][a][b][idx]!=-1){
            return dp[i][j][a][b][idx];
        }
        else{
            int x = m[s[idx]].first;
            int y = m[s[idx]].second;
            // cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<s[idx]<<endl;
            return dp[i][j][a][b][idx] = min(abs(x-i)+abs(y-j)+sol(s,x,y,a,b,idx+1),abs(x-a)+abs(y-b)+sol(s,i,j,x,y,idx+1));
        }
    }
    int minimumDistance(string s) {
        int ans=INT_MAX;
        char x='A';
        for(int i=0;i<=4;i++){
            for(int j=0;j<=5;j++){
                m[x]={i,j};
                // cout<<m[x].first<<" "<<m[x].second<<" "<<x<<endl; 
                x++;
                if(x>'Z'){
                    break;
                }
            }
        }
        // cout<<sol(s,m['C'].first,m['C'].second,m['K'].first,m['K'].second,0);
       
            for(char j='A';j<='Z';j++){
                if(j==s[0]){
                    continue;
                }
                memset(dp,-1,sizeof(dp));
                ans = min(ans,sol(s,m[s[0]].first,m[s[0]].second,m[j].first,m[j].second,0));
            }
        
        return ans;
    }
};