class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(t.begin(),t.end());
        sort(p.begin(),p.end());
        int idx=0;
        int idx1=0;
        int ans=0;
        while(idx1<t.size() && idx<p.size()){
            if(p[idx]<=t[idx1]){
                idx++;
                idx1++;
                ans++;
            }
            else{
                idx1++;
            }
        }
        return ans;
    }
};