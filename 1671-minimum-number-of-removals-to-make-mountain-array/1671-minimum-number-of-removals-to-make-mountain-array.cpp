class Solution {
public:
    int minimumMountainRemovals(vector<int>& v) {
        int n=v.size(),ans=0;
        vector<int>lis(n+1,1),lds(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>v[j]){
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(v[i]>v[j]){
                    lds[i]=max(lds[i],1+lds[j]);
                }
            }
        }
        for(int i=1;i<n-1;i++){
            if(lis[i]!=1 && lds[i]!=1)
            ans=max(ans,lis[i]+lds[i]-1);
        }
        return n-ans;
    }
};