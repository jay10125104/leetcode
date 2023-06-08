class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int ans=0;
        int row=v.size()-1;
        int col=0;
        while(row>=0 && col<v[0].size()){
            while(row>=0 && col<v[0].size() && v[row][col]>=0){
                col++;
            }
            ans+=(v[0].size()-col);
            row--;
        }
        return ans;
    }
};