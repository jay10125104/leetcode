class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
        int n =v.size();
        // we can either take min or max value in 2 way kadane algo.
        
        int ans1=0;
        int sum1=0;
        for(auto &i:v){
            sum1+=i;
            if(sum1<=0){
                sum1=0;
            }
            ans1 = max(ans1,sum1);
        }
        int sum2=0;
        int ans2=0;
        for(int i=0;i<n;i++){
            sum2+=v[i];
            if(sum2>=0){
                sum2=0;
            }
            ans2 = max(ans2,abs(sum2));
        }
        return max({ans1,ans2});
    }
};