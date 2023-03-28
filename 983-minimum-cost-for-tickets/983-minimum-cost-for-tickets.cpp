class Solution {
public:
    int mincostTickets(vector<int>& v, vector<int>& costs) {
        int dp[366];
        memset(dp,0,sizeof(dp));
        int j=0;
        for(int i=1;i<=365;i++){
            dp[i]=dp[i-1];
            if(j<v.size() && v[j]==i){
                int single = costs[0];
                single+=dp[i-1];
                int seven = costs[1];
                if((i-7)>=0){
                    seven+=dp[i-7];
                }
                int thirty = costs[2];
                if((i-30)>=0){
                    thirty+=dp[i-30];
                }
                dp[i]=min({single,seven,thirty});
                j++;
                
            }
            else{
                dp[i]=dp[i-1];
            }
            
        }
        return dp[365];
    }
};