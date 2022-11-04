class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        stack<pair<int,int>>s;
        int n=v.size();
        vector<int>ans(n);
        s.push({n-1,INT_MAX});
        for(int i=n-1;i>=0;i--){
            int count=0;
            while(s.top().second<v[i]){
                count++;
                s.pop();
            }
            int total;
            if(s.top().second==INT_MAX){
                total = count;
            }
            else{
                total = count+1;
            }
            ans[i] = total;
            s.push({i,v[i]});
        }
        return ans;
    }
};