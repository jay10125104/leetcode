class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int ans=0;
        vector<int>mx(n);
        vector<int>mn(n);
        int m=0;
        for(int i=0;i<n;i++){
            mx[i] = m;
            m = max(m,v[i]);
        }
        m=0;
        for(int i=n-1;i>=0;i--){
            mn[i] = m;
            m = max(m,v[i]);
        }
        for(int i=0;i<n;i++){
            cout<<mn[i]<<" "<<mx[i]<<endl;
            int t = min(mn[i],mx[i]);
            if(t>=v[i])
            ans+=(t-v[i]);
        }
        return ans;
    }
};