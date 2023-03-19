class Solution {
public:
    // unordered_map<pair<int,int>,int>dp;
    int ans(vector<int>&nums,long long int mask,int idx,int k){
        // cout<<"df";
        if(idx==nums.size()){
            return 1;
        }
        int ans1 = ans(nums,mask,idx+1,k);
        int ans2=0;
        int flag=0;
        for(int i=0;i<idx;i++){
            if((nums[idx]-nums[i])==k && (mask&(1<<i))){
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans2 = ans(nums,mask|(1<<idx),idx+1,k);
        }
        return ans1+ans2;
        
    }
    int beautifulSubsets(vector<int>& v, int k) {
        // memset(dp,-1,sizeof(dp));
        long long int mask=0;
        sort(v.begin(),v.end());
        return ans(v,mask,0,k)-1;
        // return 0;
    }
};