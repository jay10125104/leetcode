class Solution {
public:
    int dp[257][8];
    int ans(vector<vector<int>>&s,vector<vector<int>>&m,int idx,int visited,int x){
        if(idx==s.size()){
            return 0;
        }
        else if(dp[visited][idx]!=-1){
            return dp[visited][idx];
        }
        else{
            int sol=0;
            for(int i=0;i<m.size();i++){
                int x = pow(2,i);
                if((visited&x)==0){
                    int t = visited;
                    t = t|x;
                    int count=0;
                    cout<<idx<<" "<<t<<" "<<endl;
                    for(int j=0;j<s[0].size();j++){
                            if(s[idx][j]==m[i][j]){
                                count++;
                            }
                    }
                    sol = max(sol,count+ans(s,m,idx+1,t,x));
                }
            }
            
            return dp[visited][idx]=sol;
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        int x = pow(2,m.size())-1;
        memset(dp,-1,sizeof(dp));
        cout<<x<<endl;
        return ans(s,m,0,0,x);
    }
};