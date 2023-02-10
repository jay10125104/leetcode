class Solution {
public:
int dp[101][101];
int v[101][101];
int ans(string &s,int idx,int k){
    if(idx==s.size()){
        return 100;
    }
    else if(k==0){
        return v[idx][s.size()-1];
    }
    else if(dp[idx][k]!=-1){
        return dp[idx][k];
    }
    else{
        int mx = 100;
        for(int i=idx;i<s.size()-1;i++){
            mx = min(mx,v[idx][i] + ans(s,i+1,k-1));
        }
        return dp[idx][k] = mx;
    }
}
    int palindromePartition(string s, int k) {
    int n=s.size();
    memset(dp,-1,sizeof(dp));
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int left=i;
            int right=j;
            int count=0;
            while(left<=right){
                if(s[left]!=s[right]){
                    count++;
                }
                left++;
                right--;
            }
            v[i][j]=count;
        }
    }
    k--;
    return ans(s,0,k);
    }
};