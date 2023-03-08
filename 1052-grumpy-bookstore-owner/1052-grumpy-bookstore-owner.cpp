class Solution {
public:
    int maxSatisfied(vector<int>& v, vector<int>& t, int x) {
        int n=v.size();
        vector<int>sum(n);
        int mid=0;
        for(int i=0;i<n;i++){
            mid+=v[i];
            t[i]=!t[i];
            sum[i]=mid;
        }
        vector<int>prev(n);
        vector<int>next(n);
        mid=0;
        for(int i=0;i<n;i++){
            prev[i]=mid;
            if(t[i]){
                mid+=v[i];
            }
            
        }
        mid=0;
         for(int i=n-1;i>=0;i--){
            next[i]=mid;
            if(t[i]){
                mid+=v[i];
            }
             
        }
        // for(int i=0;i<n;i++){
        //     cout<<prev[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<next[i]<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=0;(i+x)<=n;i++){
            int prevsum=((i==0)?(0):(sum[i-1]));
            int fixed = sum[i+x-1]-prevsum;
            // cout<<fixed<<endl;
            ans = max(ans,fixed+next[i+x-1]+prev[i]);
        }
        return ans;
        
    }
};