class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.size();
        int prev[n];
        memset(prev,0,sizeof(prev));
        int next[n];
        memset(next,0,sizeof(next));
        int count=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=count;
            next[i]=sum;
            if(s[i]=='1'){
                count++;
            }
        }
        sum=0;
        count=0;
        for(int i=0;i<n;i++){
            sum+=count;
            prev[i]=sum;
            if(s[i]=='1'){
                count++;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prev[i]+next[i];
        }
        return ans;
        
    }
};