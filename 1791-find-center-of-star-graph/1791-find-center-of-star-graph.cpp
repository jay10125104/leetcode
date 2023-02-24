class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>m;
        for(auto &i:edges){
            m[i[0]]++;
            m[i[1]]++;
        }
        for(auto &i:m){
            if(i.second>1){
                return i.first;
            }
        }
        return -1;
    }
};