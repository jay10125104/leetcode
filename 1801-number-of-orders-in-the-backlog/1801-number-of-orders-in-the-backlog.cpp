class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& v) {
        priority_queue<pair<int,int>>q1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
        for(auto &i:v){
            if(i[2]==1){
               int left = i[1];
                while(q1.size() && left && q1.top().first>=i[0]){
                    auto it = q1.top();
                    int rem=it.second;
                    q1.pop();
                    int req = min(left,it.second);
                    left-=req;
                    rem-=req;
                    if(rem!=0){
                        q1.push({it.first,rem});
                    }
                }
                if(left){
                    q2.push({i[0],left});
                }
                // cout<<left<<" ";
            }
            else{
                int left = i[1];
                while(q2.size() && left && q2.top().first<=i[0]){
                    auto it = q2.top();
                    q2.pop();
                    int rem=it.second;
                    int req = min(left,it.second);
                    left-=req;
                    rem-=req;
                    if(rem!=0){
                        q2.push({it.first,rem});
                    }
                }
                if(left){
                    q1.push({i[0],left});
                }
                // cout<<left<<" ";
            }
        }
        long long int ans=0;
        int mod=1000000007;
        while(q1.size()){
            ans = (ans%mod + q1.top().second%mod)%mod;
            // cout<<q1.top().second<<" ";
            q1.pop();
        }
        while(q2.size()){
            // ans+=q2.top().second;
            ans = (ans%mod + q2.top().second%mod)%mod;
            // cout<<q2.top().second<<" ";
            q2.pop();
        }
        return ans;
    }
};