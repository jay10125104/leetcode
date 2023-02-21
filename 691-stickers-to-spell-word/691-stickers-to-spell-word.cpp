class Solution {
public:
    long long int dp[51][1<<16];
    long long int ans(vector<string>&s,string &target,int idx,int mask){
        if(idx==s.size()){
            int x = __builtin_popcount(mask);
            // cout<<x<<" ";
            if(x==target.size()){
                return 0;
            }
            else{
                return INT_MAX;
            }
        }
        else if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        long long int x = ans(s,target,idx+1,mask);
        long long int msk=mask;
        vector<int>vi(26);
        for(int i=0;i<s[idx].size();i++){
            vi[s[idx][i]-'a']++;
        }
        for(int i=0;i<target.size();i++){
            if(((msk&(1<<i))==0) && vi[target[i]-'a']){
                vi[target[i]-'a']--;
                msk|=(1<<i);
            }
        }
        long long int ti = INT_MAX;
        if(mask!=msk){
            ti = 1+ans(s,target,idx,mask|msk);
        }
        long long int y = 1+ans(s,target,idx+1,mask|msk);
        return dp[idx][mask] = min({x,y,ti});
    }
    int minStickers(vector<string>& s, string target) {
       memset(dp,-1,sizeof(dp));
        int x = ans(s,target,0,0);
        return (x==INT_MAX)?(-1):(x);
    }
};