class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& v) {
        int ans=0;
        int k=v.size();
        for(int i=0;i<(1<<k);i++){
            vector<int>t(n);
            for(int j=0;j<k;j++){
                int mask=i;
                if(mask&(1<<j)){
                    t[v[j][1]]++;
                    t[v[j][0]]--;
                }
            }
            int flag=0;
            for(auto it:t){
                if(it!=0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans=max(ans,__builtin_popcount(i));
            }
        }
        return ans;
    }
};