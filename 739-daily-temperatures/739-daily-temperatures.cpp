class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<pair<int,int>>s;
        int n=v.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(s.size() && s.top().first<=v[i]){
                s.pop();
            }
            if(s.size()){
                ans[i] = s.top().second - i;
            }
            s.push({v[i],i});
        }
        return ans;
        
    }
};