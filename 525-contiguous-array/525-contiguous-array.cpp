class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>m;
        m[0]=-1;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                sum++;
            }
            else{
                sum--;
            }
            int req = sum;
            if(m.find(req)!=m.end()){
                ans = max(i-m[req],ans);
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
            // cout<<sum<<" "<<m[sum]<<endl;
            
        }
        return ans;
    }
};