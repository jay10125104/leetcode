class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int>m;
        map<int,int>m1;
        for(auto &i:mat){
            m[i[0]]++;
            m1[i[1]]++;
        }
        vector<int>one;
        vector<int>two;
        for(auto &i:m1){
            if(i.second==1){
                two.push_back(i.first);
            }
        }
        for(auto &i:m){
            if(m1[i.first]==0){
                one.push_back(i.first);
            }
        }
        return {one,two};
    }
};