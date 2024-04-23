class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        int c1=0,c2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        for(auto &i:nums){
            if((c1==0)&&(el2!=i)){
                c1++;
                el1=i;
            }
            else if((c2==0)&&(el1!=i)){
                c2++;
                el2=i;
            }
            else if(el1==i){
                c1++;
            }
            else if(el2==i){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(auto &i:nums){
            if(i==el1){
                c1++;
            }
            if(i==el2){
                c2++;
            }
        }
        vector<int>ans;
        if(c1>n){
            ans.push_back(el1);
        }
        if(c2>n){
            ans.push_back(el2);
        }
        return ans;
        
    }
};