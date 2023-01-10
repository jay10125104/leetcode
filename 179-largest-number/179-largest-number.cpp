bool cmp(string s,string t){
    return (s+t)<(t+s);
}
class Solution {
public:
    string largestNumber(vector<int>& v) {
        vector<string>nums;
        for(auto &i:v){
            nums.push_back(to_string(i));
        }
        sort(nums.begin(),nums.end(),cmp);
        reverse(nums.begin(),nums.end());
        string ans="";
        int flag=0;
        for(auto &i:nums){
            if(i!="0"){
                flag=1;
            }
            if(flag)
            ans+=i;
        }
        return (ans=="")?("0"):(ans);
        
    }
};