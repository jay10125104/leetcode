class Solution {
public:
    int partitionString(string s) {
        int count=0;
        vector<int>ans(26,0);
        for(auto i:s){
            if(ans[i-'a']){
                count++;
//                 for(auto i:ans){
//                     cout<<i<<" ";
                    
//                 }
                // cout<<endl;
                for(auto &i:ans){
                    i=0;
                }
                ans[i-'a']++;
                // cout<<i<<" ";
            }
            else{
                ans[i-'a']++;
            }
        }
        return count+1;
    }
};