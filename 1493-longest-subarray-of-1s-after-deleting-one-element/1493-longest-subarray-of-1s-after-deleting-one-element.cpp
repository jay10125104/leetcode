class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        vector<int>prev(n);
        vector<int>next(n);
        prev[0] = ((v[0]==1)?(1):(0));
        // cout<<prev[0]<<" ";
        for(int i=1;i<n;i++){
            if(v[i]){
                prev[i] =prev[i-1]+1;
            }
            else{
                prev[i]=0;
            }
            // cout<<prev[i]<<" ";
        }
        cout<<endl;
        
        next[n-1] = ((v[n-1]==1)?(1):(0));
        for(int i=n-2;i>=0;i--){
            if(v[i]){
                next[i] =next[i+1]+1;
            }
            else{
                next[i]=0;
            }
            // cout<<next[i]<<" ";
        }
        int ans=0;
        for(int i=0;i<=n-1;i++){
            int x = ((i==0)?(0):(prev[i-1]));
             int y = ((i==n-1)?(0):(next[i+1]));
            // cout<<x<<" "<<y<<endl;
            ans = max(ans,x+y);
        }
        return ans;
    }
};