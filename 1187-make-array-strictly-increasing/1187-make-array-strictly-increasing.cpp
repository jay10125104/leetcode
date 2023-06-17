class Solution {
public:
    int dp[2001][2001][2];
    int ans(vector<int>&arr1,vector<int>&arr2,int idx1,int idx2,int pick){
        if(idx1==arr1.size()){
            return 0;
        }
        else if(dp[idx1][idx2][pick]!=-1){
            return dp[idx1][idx2][pick];
        }
        else{
            int prev = -1;
            if(pick==1){
                prev=arr2[idx2];
            }
            else{
                prev=arr1[idx2];
            }
            int mn=arr1.size()+1;
            if(prev<arr1[idx1]){
                mn=min(mn,ans(arr1,arr2,idx1+1,idx1,0));
            }
            
                int low=0;
                int high=arr2.size()-1;
                int sol=-1;
                while(low<=high){
                    int mid = (low+high)/2;
                    if(arr2[mid]>prev){
                        sol=mid;
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                if(sol!=-1){
                    mn=min(mn,1+ans(arr1,arr2,idx1+1,sol,1));
                }
            return dp[idx1][idx2][pick]=mn;
            
        }
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp,-1,sizeof(dp));
        arr2.insert(arr2.begin(),-1);
        sort(arr2.begin(),arr2.end());
        int sol=ans(arr1,arr2,0,0,1);
        return (sol>arr1.size())?(-1):(sol);
    }
};