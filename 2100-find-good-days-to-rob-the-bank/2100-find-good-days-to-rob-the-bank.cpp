class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int k) {
        int n=v.size();
        int prev[n];
        int next[n];
        memset(prev,0,sizeof(prev));
        memset(next,0,sizeof(next));
        prev[0]=0;
        for(int i=1;i<n;i++){
            if(v[i]<=v[i-1]){
                prev[i]=prev[i-1]+1;
            }
            else{
                prev[i] = 0;
            }
        }
        next[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(v[i]<=v[i+1]){
                next[i]=next[i+1]+1;
            }
            else{
                next[i] = 0;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(prev[i]>=k && next[i]>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};