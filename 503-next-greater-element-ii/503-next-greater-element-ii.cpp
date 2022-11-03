class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        stack<int>s;
        int n=v.size();
        for(int i =n-1;i>=0;i--){
            while(s.size() && s.top()<=v[i]){
                s.pop();
            }
            s.push(v[i]);
        }
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(s.size() && s.top()<=v[i]){
                s.pop();
            }
            if(s.size()){
                ans[i] = s.top();
            }
            s.push(v[i]);
        }
        return ans;
    }
};