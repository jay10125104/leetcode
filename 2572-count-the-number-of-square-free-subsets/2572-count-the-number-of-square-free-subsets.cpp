class Solution {
public:
    int dp[1001][1<<10];
    int mod = 1000000007;
    vector<int>v = {2,3,5,7,11,13,17,19,23,29};
    int helper(int n){
        int mask=0;
        for(int i=0;i<v.size();i++){
            int cnt=0;
            while(n%v[i]==0){
                n=n/v[i];
                cnt++;
            }
            if(cnt==1){
                mask|=(1<<i);
            }
            else if(cnt){
                return -1;
            }
        }
        return mask;
    }
    int ans(vector<int>&nums,int idx,int mask){
        // cout<<idx<<" "<<mask<<endl;
        if(idx==nums.size()){
            return 1;
        }
        else if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        else{
            int x = ans(nums,idx+1,mask);
            int y=0;
            int msk = helper(nums[idx]);
            // cout<<msk<<" ";
            if(msk!=-1 && (mask&msk)==0){
                y = ans(nums,idx+1,mask|msk);
            }
            return dp[idx][mask] = (x%mod+y%mod)%mod;
        }
    }
    int squareFreeSubsets(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return ans(nums,0,0)-1;
    }
};