class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        for(auto &i:piles){
            q.push(i);
        }
        while(k--){
            int x = q.top();
            q.pop();
            x = x - (x/2);
            q.push(x);
        }
        int ans=0;
        while(q.size()){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};