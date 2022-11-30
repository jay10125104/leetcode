class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto &i:arr){
            m[i]++;
        }
        map<int,int>m1;
        for(auto &i:m){
            m1[i.second]++;
            if(m1[i.second]==2){
                return false;
            }
        }
        return true;
    }
};