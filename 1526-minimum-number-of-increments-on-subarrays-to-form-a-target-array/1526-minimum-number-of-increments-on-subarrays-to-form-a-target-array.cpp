class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int>s;
        int ans = target[0];
        for(int i=0;i<target.size();i++){
            while(s.size() && s.top()<target[i]){
                ans+=(target[i]-s.top());
                s.pop();
                s.push(target[i]);
            }
            s.push(target[i]);
            // cout<<ans<<" ";
        }
        return ans;
    }
};