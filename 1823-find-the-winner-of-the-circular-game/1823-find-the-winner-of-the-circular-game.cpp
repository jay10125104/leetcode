class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int>q;
        for(int i=1;i<=n;i++){
            q.push_back(i);
        }
        while(q.size()!=1){
            int x = q.size();
            int count=0;
            while(count!=k){
                int x =q.front();
                q.pop_front();
                count++;
                q.push_back(x);
            }
            q.pop_back();
        }
        return q.front();
    }
};