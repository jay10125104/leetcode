class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans=0;
        int n=apples.size();
        int idx=0;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<=40000;i++){
            while(q.size() && (abs(q.top().first)<=i||q.top().second==0)){
                q.pop();
            }
            if(i<n){
                if(apples[i])
                q.push({(i+days[i])*-1,apples[i]});
                // idx++;
            }
            if(q.size()){
                auto it = q.top();
                q.pop();
                int x = it.first;
                int y = it.second;
                y--;
                if(y)
                q.push({x,y});
                ans++;
            }
        }
        return ans;
    }
};