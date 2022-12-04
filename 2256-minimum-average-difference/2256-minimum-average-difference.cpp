class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size()==0){
            return nums[0];
        }
        long long int sum=0;
        for(auto i:nums){
            sum+=i;
            
        }
        long long int sum2=0;
        long long int k=1;
        long int g = nums.size()-1;
                vector<long long int>ans;
       

        for(auto i:nums){
            sum-=i;
            sum2+=i;
            if(g==0){
                g=1;
            }
           
            ans.push_back(abs((sum2/k) - (sum/g) ));
            k++;
            g--;
        }
        vector<long long int>v=ans;
        
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(v[i]==ans[0]){
                return i;
            }
        }
        return ans[ans.size()-1];
        
    }
};