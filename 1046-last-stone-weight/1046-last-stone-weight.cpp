class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>v;
       for(auto i:s){
           v.push(i);
       }
        while(v.size()!=1){
            int x = v.top();
            v.pop();
            int y = v.top();
            v.pop();
            int ans = x-y;
            v.push(ans);
        }
        return v.top();
    }
};