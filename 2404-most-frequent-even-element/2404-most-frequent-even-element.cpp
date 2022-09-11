class Solution {
public:
    int mostFrequentEven(vector<int>& v) {
        map<int,int>m;
        for(auto i:v){
            m[i]++;
        }
        int ans=-1;
        int mx = 0;
        vector<int>sol;
        for(auto i:m){
            if(i.first%2==0 && mx<i.second){
                ans =i.first;
                mx=i.second;
            }
        }
        return ans;
    }
};