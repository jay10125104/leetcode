class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        map<int,vector<int>>m;
        int sum=0;
        for(auto &i:nums){
            m[(i%3)].push_back(i);
            sum+=i;
        }
        sort(m[1].begin(),m[1].end());
        sort(m[2].begin(),m[2].end());
        if(sum%3==0){
            return sum;
        }
        else{
            if(sum%3==2){
                int ans = 0;
                if(m[1].size()>=2){
                    int x = m[1][0]+m[1][1];
                    ans = max(ans,sum-x);
                }
                if(m[2].size()>=1){
                    ans = max(ans,sum-m[2][0]);
                }
                return ans;
            }
            else{
                int ans = 0;
                if(m[1].size()){
                    int x = m[1][0];
                    ans = max(ans,sum-x);
                }
                if(m[2].size()>=2){
                    ans = max(ans,sum-m[2][1]-m[2][0]);
                }
                return ans;
            }
        }
        
    }
};