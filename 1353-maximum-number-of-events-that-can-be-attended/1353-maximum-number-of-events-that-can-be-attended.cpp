class Solution {
public:
    int maxEvents(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int i=0;
        int ans=0;
        priority_queue<int>q;
        int n=v.size();
        for(int j=1;j<=100000;j++){
            while(q.size() && abs(q.top())<j){
                q.pop();
            }
            while(i<n && v[i][0]<=j){
                q.push(-1*v[i][1]);
                i++;
            }
            if(q.size()){
                // q.top();/
                q.pop();
                ans++;
            }
        }
        return ans;
    }
};