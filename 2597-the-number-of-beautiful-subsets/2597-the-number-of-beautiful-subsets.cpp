class Solution {
public:
    // int dp[1<<20][20];
    int ans(vector<int>&nums,long long int mask,int idx,int k){
        // cout<<"df";
        if(idx==nums.size()){
            return 1;
        }
        // else if(dp[mask][idx]!=-1){
        //     return dp[mask][idx];
        // }
        int ans1 = ans(nums,mask,idx+1,k);
        int ans2=0;
        int flag=0;
        for(int i=0;i<idx;i++){
            if((nums[idx]-nums[i])==k && (mask&(1<<i))){
                flag=1;
            }
        }
        if(flag==0){
            ans2 = ans(nums,mask|(1<<idx),idx+1,k);
        }
        return  ans1+ans2;
        
    }
    int beautifulSubsets(vector<int>& v, int k) {
       // vector<vector<int>>dp((1<<v.size()),vector<int>(v.size(),-1));
        long long int mask=0;
        sort(v.begin(),v.end());
        return ans(v,mask,0,k)-1;
        // return 0;
    }
};