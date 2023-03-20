class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=0){
                continue;
            }
            int flag1=1;
            int flag2=1;
            if((i>=1) && (v[i-1]==1)){
                flag1=0;
            }
            if(((i+1)<v.size()) && (v[i+1]==1)){
                flag2=0;
                
            }
            // cout<<flag2<<" "<<v[i+1]<<" ";
            if(flag1 && flag2){
                ans++;
                v[i]=1;
            }
            // cout<<i<<" "<<ans<<endl;/
        }
        
        return ans>=n;
        
    }
};