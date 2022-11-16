class Solution {
public:
    // map<pair<int,vector<int>>,int>dp;
    int ans(vector<int>&v,int idx,vector<int>&t){
        if(idx==v.size()){
            int it = 0;
            for(auto &i:t){
                it = max(i,it);
            }
            return it;
        }
        else{
            int mn = INT_MAX;
            for(int i=0;i<t.size();i++){
                t[i]+=v[idx];
                mn = min(ans(v,idx+1,t),mn);
                t[i]-=v[idx];
            }
            return mn;
        }
    }
    int distributeCookies(vector<int>& v, int k) {
        int n=v.size();
        vector<int>t(k);
        return ans(v,0,t);
    }
};