class Solution {
public:
    int longestMountain(vector<int>& v) {
        int n=v.size();
        int prev[n];
        int next[n];
        memset(prev,0,sizeof(prev));
        memset(next,0,sizeof(next));
        for(int i=1;i<n;i++){
            if((v[i]-v[i-1])>0){
                prev[i]=prev[i-1]+1;
            }
            else{
                prev[i]=0;
            }
            // cout<<prev[i]<<" ";
        }
        // cout<<endl;
        for(int i=n-2;i>=0;i--){
            if((v[i]-v[i+1])>0){
                next[i]=next[i+1]+1;
            }
            else{
                next[i]=0;
            }
            // cout<<next[i]<<" ";
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prev[i]&&next[i]){
                ans = max(ans,prev[i]+next[i]+1);
            }
        }
        return ans;
    }
};