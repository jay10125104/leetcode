class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<pair<int,int>>v;
        int even=0;
        int odd=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            v.push_back({even,odd});
            
            if(i%2==0){
                even+=nums[i];
            }
            else{
                odd+=nums[i];
            }
        }
        vector<pair<int,int>>t;
        even=0;
        odd=0;
        for(int i=n-1;i>=0;i--){
            t.push_back({odd,even});
            if(i%2==0){
                even+=nums[i];
            }
            else{
                odd+=nums[i];
            }   
        }
        reverse(t.begin(),t.end());
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<v[i].first<<" "<<v[i].second<<" "<<t[i].first<<" "<<t[i].second<<endl;
            int one=v[i].first+t[i].first;
            int two=v[i].second+t[i].second;
            // cout<<one<<" "<<two<<endl;
            ans+=(one==two);
        }
        return ans;
    }
};