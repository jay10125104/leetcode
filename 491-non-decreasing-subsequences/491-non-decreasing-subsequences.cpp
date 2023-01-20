
class Solution {
public:
    set<vector<int>>ans;
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
       for(int i=1;i<pow(2,n);i++){
           int prev = -200;
           int flag=1;
           vector<int>v;
           for(int j=0;j<n;j++){
               int mask = (1<<j);
               if(i&mask){
                   if(prev<=nums[j]){
                   v.push_back(nums[j]);
                       prev=nums[j];
                       }
                   else{
                       flag=0;
                       break;
                   }
                   
               }
               
           }
           if(flag && v.size()>=2){
            ans.insert(v);   
           }
       } 
        vector<vector<int>>sol;
        for(auto &i:ans){
            sol.push_back(i);
        }
        // sort(sol.begin(),sol.end(),cmp);
        return sol;
    }
};