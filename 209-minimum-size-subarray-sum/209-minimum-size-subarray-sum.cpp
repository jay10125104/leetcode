class Solution {
public:
    int minSubArrayLen(int val, vector<int>& v) {
        int i=0;
        int j=0;
        int flag=0;
        int sum=0;
        int ans = v.size();
        int n=v.size();
        while(j<n){
            sum+=v[j];
            if(sum>=val){
                while(sum>=val){
                    sum-=v[i];
                    ans=min(ans,j-i+1);
                    flag=1;
                    i++;
                }
            }
            j++;
        }
        if(flag==1){
            return ans;
        }
        else{
            return 0;
        }
        
    }
};