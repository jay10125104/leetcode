class Solution {
public:
    int dp[10][1<<9];
    int ans(vector<vector<char>>&v,int idx,int mask){
        if(idx==v.size()){
            return 0;
        }
        else if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        else{
            int mx=0;
            int n=v[0].size();
            for(int i=0;i<pow(2,n);i++){
                if(mask&i){
                    continue;
                }
                string mid="00000000";
                int Mask=0;
                int flag=1;
                int count=0;
                for(int j=0;j<n;j++){
                    if(((1<<j)&i)){
                        mid[j]='1';
                        count++;
                        int mid2 = (1<<(j+1));
                        if(j>=1){
                        int mid3 = (1<<(j-1));
                        Mask=Mask|mid3;
                        }
                        Mask = Mask|mid2;
                    }
                    if((j>=1) && mid[j-1]=='1' && mid[j]=='1'){
                        flag=0;
                        break;
                    }
                    if(mid[j]=='1' && v[idx][j]=='#'){
                        flag=0;
                        break;
                    }
                    
                }
                if(flag){
                    mx = max(mx,count+ans(v,idx+1,Mask));
                }
            }
            // cout<<idx<<" "<<mask<<" "<<mx<<endl;
            return dp[idx][mask] = mx;
        }
    }
    int maxStudents(vector<vector<char>>& v) {
        memset(dp,-1,sizeof(dp));
        return ans(v,0,0);
    }
};